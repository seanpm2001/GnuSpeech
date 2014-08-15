#import "GSTextRun.h"

#import "NSRegularExpression-GSExtensions.h"
#import "NSString-Extensions.h"

@implementation GSTextRun
{
    GSTextParserMode _mode;
    NSMutableString *_string;
}

- (id)initWithMode:(GSTextParserMode)mode;
{
    if ((self = [super init])) {
        _mode = mode;
        _string = [[NSMutableString alloc] init];
    }

    return self;
}

#pragma mark - Debugging

- (NSString *)description;
{
    return [NSString stringWithFormat:@"<%@: %p> mode: %@, string: '%@'",
            NSStringFromClass([self class]), self,
            [GSTextParserModeDescription(self.mode) stringByPaddingToLength:8 withString:@" " startingAtIndex:0], self.string];
}

#pragma mark -

- (void)stripPunctuation;
{
    if (self.mode == GSTextParserMode_Normal || self.mode == GSTextParserMode_Emphasis) {
        [self _punc1_replaceSingleCharacters];

        // These used to be part of punc2.  Not sure where they are getting there source text, that they want to delete all this stuff.
        [_string replaceOccurrencesOfString:@"(?)" withString:@"" options:0];
        [_string replaceOccurrencesOfString:@"(!)" withString:@"" options:0];

        [_string replaceOccurrencesOfString:@"---" withString:@", " options:0];
        [_string replaceOccurrencesOfString:@"--"  withString:@", " options:0];

        // Replace these characters with words, so we don't have to check again later if they are isolated.  We'll know all remaining ones are NOT isolated.
        [self _replaceIsolatedCharacters];

        [self _punc1_deleteSingleQuotes];
        [self _punc1_deleteSingleCharacters];

        [self _punc1_deleteNonNumberPlusAndMinus];
    }
}

// Replace + and - that are not part of numbers.
// A digit before or after is fine, but if no digit before and none after, then remove the characters
// Call _AFTER_ replacing isolated plus/minus.
- (void)_punc1_deleteNonNumberPlusAndMinus;
{
    NSError *error;

    NSRegularExpression *re_1   = [[NSRegularExpression alloc] initWithPattern:@"^\\+([^0-9])"         options:0 error:&error];
    NSRegularExpression *re_2   = [[NSRegularExpression alloc] initWithPattern:@"([^0-9])\\+$"         options:0 error:&error];
    NSRegularExpression *re_3   = [[NSRegularExpression alloc] initWithPattern:@"([^0-9])\\+([^0-9])" options:0 error:&error];
    if (re_1 == nil) { NSLog(@"re1: error: %@", error); }
    if (re_2 == nil) { NSLog(@"re2: error: %@", error); }
    if (re_3 == nil) { NSLog(@"re3: error: %@", error); }

    // Remove the single quote in all matching cases.
    [re_1 replaceMatchesInString:_string options:0 withTemplate:@"$1"];
    [re_2 replaceMatchesInString:_string options:0 withTemplate:@"$1"];
    [re_3 replaceMatchesInString:_string options:0 withTemplate:@"$1$2"]; // Interesting, " a+ +a ", 2nd doesn't get replaced because it matched before, so search continues after.
}

- (void)_punc1_replaceSingleCharacters;
{
    [_string replaceOccurrencesOfString:@"[" withString:@"(" options:0];
    [_string replaceOccurrencesOfString:@"]" withString:@")" options:0];
}

/// Replace isolated string with words.  Isolated means surrounded by space, or beginning/end of string.
- (void)_replaceIsolatedString:(NSString *)str withString:(NSString *)replacement;
{
    NSParameterAssert(str != nil);
    NSParameterAssert(replacement != nil);

    NSString *middle = [NSString stringWithFormat:@" %@ ", str];
    NSString *prefix = [str stringByAppendingString:@" "];
    NSString *suffix = [@" " stringByAppendingString:str];

    NSString *middleReplacement = [NSString stringWithFormat:@" %@ ", replacement];
    NSString *prefixReplacement = [replacement stringByAppendingString:@" "];
    NSString *suffixReplacement = [@" " stringByAppendingString:replacement];


    [_string replaceOccurrencesOfString:middle withString:middleReplacement  options:0];
    if ([_string hasPrefix:prefix]) [_string replaceCharactersInRange:NSMakeRange(0, 2) withString:prefixReplacement];
    if ([_string hasSuffix:suffix]) [_string replaceCharactersInRange:NSMakeRange([_string length] - 2, 2) withString:suffixReplacement];
}

// punc1 used to check for isolated characters and not delete them, and then check for them again in punc2 to replace them.
// I'm going to just replace them first, to save future checks.

/// Replace isolated + and - characters with words.  Isolated means surrounded by space, or beginning/end of string.
- (void)_replaceIsolatedCharacters;
{
    [self _replaceIsolatedString:@"+" withString:@"plus"];
    [self _replaceIsolatedString:@"-" withString:@"minus"];

    [self _replaceIsolatedString:@"<" withString:@"is less than"];
    [self _replaceIsolatedString:@">" withString:@"is greater than"];
    [self _replaceIsolatedString:@"=" withString:@"equals"];
    [self _replaceIsolatedString:@"&" withString:@"and"];
    [self _replaceIsolatedString:@"@" withString:@"at"];

}

/// Delete single quotes, except those that have an alpha character before and after.
- (void)_punc1_deleteSingleQuotes;
{
    NSError *error;

    NSRegularExpression *re_singleQuoteAtStartOrEnd   = [[NSRegularExpression alloc] initWithPattern:@"^'|'$"                     options:0 error:&error];
    NSRegularExpression *re_singleQuoteBeforeNonAlpha = [[NSRegularExpression alloc] initWithPattern:@"([:alpha:])'([:^alpha:])"  options:0 error:&error];
    NSRegularExpression *re_singleQuoteAfterNonAlpha  = [[NSRegularExpression alloc] initWithPattern:@"([:^alpha:])'([:alpha:])"  options:0 error:&error];
    NSRegularExpression *re_isolatedSingleQuote       = [[NSRegularExpression alloc] initWithPattern:@"([:^alpha:])'([:^alpha:])" options:0 error:&error];
    if (re_singleQuoteAtStartOrEnd == nil)   { NSLog(@"re1: error: %@", error); }
    if (re_singleQuoteBeforeNonAlpha == nil) { NSLog(@"re2: error: %@", error); }
    if (re_singleQuoteAfterNonAlpha == nil)  { NSLog(@"re3: error: %@", error); }
    if (re_isolatedSingleQuote == nil)       { NSLog(@"re4: error: %@", error); }

    // Remove the single quote in all matching cases.
    [re_singleQuoteAtStartOrEnd   replaceMatchesInString:_string options:0 withTemplate:@""];
    [re_singleQuoteBeforeNonAlpha replaceMatchesInString:_string options:0 withTemplate:@"$1$2"];
    [re_singleQuoteAfterNonAlpha  replaceMatchesInString:_string options:0 withTemplate:@"$1$2"];
    [re_isolatedSingleQuote       replaceMatchesInString:_string options:0 withTemplate:@"$1$2"];}

- (void)_punc1_deleteSingleCharacters;
{
    NSCharacterSet *set = [NSCharacterSet characterSetWithCharactersInString:@"\"`#*\\^_|~{}"];

    [_string deleteCharactersInSet:set];
}

@end
