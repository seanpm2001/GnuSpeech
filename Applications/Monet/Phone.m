#import "Phone.h"

#import <Foundation/Foundation.h>
#import "NSObject-Extensions.h"
#import "NSString-Extensions.h"

#import "AppController.h"
#import "CategoryNode.h"
#import "CategoryList.h"
#import "Parameter.h"
#import "ParameterList.h"
#import "Target.h"
#import "TargetList.h"
#import "SymbolList.h"

@implementation Phone

- (id)init;
{
    if ([super init] == nil)
        return nil;

    phoneSymbol = nil;
    comment = nil;

    categoryList = [[CategoryList alloc] initWithCapacity:15];
    parameterList = [[TargetList alloc] initWithCapacity:15];
    metaParameterList = [[TargetList alloc] initWithCapacity:15];
    symbolList = [[TargetList alloc] initWithCapacity:15];

    return self;
}

- (id)initWithSymbol:(NSString *)newSymbol;
{
    if ([self init] == nil)
        return nil;

    [self setSymbol:newSymbol];

    return self;
}

- (id)initWithSymbol:(NSString *)newSymbol parmeters:(ParameterList *)parms metaParameters:(ParameterList *)metaparms symbols:(SymbolList *)symbols;
{
    int count, index;
    Target *newTarget;

    if ([self init] == nil)
        return nil;

    [self setSymbol:newSymbol];

    count = [parms count];
    for (index = 0; index < count; index++) {
        newTarget = [[Target alloc] initWithValue:[[parms objectAtIndex:index] defaultValue] isDefault:YES];
        [parameterList addObject:newTarget];
        [newTarget release];
    }

    count = [metaparms count];
    for (index = 0; index < count; index++) {
        newTarget = [[Target alloc] initWithValue:[[metaparms objectAtIndex:index] defaultValue] isDefault:YES];
        [metaParameterList addObject:newTarget];
        [newTarget release];
    }

    count = [symbols count];
    for (index = 0; index < count; index++) {
        newTarget = [[Target alloc] initWithValue:[[symbols objectAtIndex:index] defaultValue] isDefault:YES];
        [symbolList addObject:newTarget];
        [newTarget release];
    }

    return self;
}

- (void)dealloc;
{
    [phoneSymbol release];
    [comment release];

    [categoryList release];
    [parameterList release];
    [metaParameterList release];
    [symbolList release];

    [super dealloc];
}

- (NSString *)symbol;
{
    return phoneSymbol;
}

- (void)setSymbol:(NSString *)newSymbol;
{
    int count, index;

    if (newSymbol == phoneSymbol)
        return;

    [phoneSymbol release];
    phoneSymbol = [newSymbol retain];

    count = [categoryList count];
    for (index = 0; index < count; index++) {
        CategoryNode *aCategory;

        aCategory = [categoryList objectAtIndex:index];
        if ([aCategory isNative]) {
            [aCategory setSymbol:newSymbol];
            return;
        }
    }
}

- (NSString *)comment;
{
    return comment;
}

- (void)setComment:(NSString *)newComment;
{
    if (newComment == comment)
        return;

    [comment release];
    comment = [newComment retain];
}

- (CategoryList *)categoryList;
{
    return categoryList;
}

- (void)addToCategoryList:(CategoryNode *)aCategory;
{
}

- (TargetList *)parameterList;
{
    return parameterList;
}

- (TargetList *)metaParameterList;
{
    return metaParameterList;
}

- (TargetList *)symbolList;
{
    return symbolList;
}

//
// Archiving
//

- (id)initWithCoder:(NSCoder *)aDecoder;
{
    unsigned archivedVersion;
    int i, j;
    CategoryList *mainCategoryList;
    CategoryNode *temp1;
    char *string;

    if ([super initWithCoder:aDecoder] == nil)
        return nil;

    NSLog(@"[%p]<%@>  > %s", self, NSStringFromClass([self class]), _cmd);
    archivedVersion = [aDecoder versionForClassName:NSStringFromClass([self class])];
    NSLog(@"aDecoder version for class %@ is: %u", NSStringFromClass([self class]), archivedVersion);
#ifdef PORTING
    mainCategoryList = NXGetNamedObject(@"mainCategoryList", NSApp);

    [aDecoder decodeValuesOfObjCTypes:"**", &phoneSymbol, &comment];

    parameterList = [[aDecoder decodeObject] retain];
    metaParameterList = [[aDecoder decodeObject] retain];
    symbolList = [[aDecoder decodeObject] retain];

    if (categoryList)
        [categoryList release];

    [aDecoder decodeValueOfObjCType:"i" at:&i];
//	printf("TOTAL Categories for %s = %d\n", phoneSymbol, i);

    categoryList = [[CategoryList alloc] initWithCapacity:i];

    for (j = 0; j<i; j++)
    {
        [aDecoder decodeValueOfObjCType:"*" at:&string];
        if ((temp1 = [mainCategoryList findSymbol:string]) )
        {
//			printf("Read category: %s\n", string);
            [categoryList addObject:temp1];
        }
        else
        {
//			printf("Read NATIVE category: %s\n", string);
            if (strcmp(phoneSymbol, string)!=0)
            {
                printf("NATIVE Category Wrong... correcting: %s -> %s", string, phoneSymbol);
                [categoryList addNativeCategory:phoneSymbol];
            }
            else
                [categoryList addNativeCategory:string];
        }
        free(string);
    }
#endif
    NSLog(@"[%p]<%@> <  %s", self, NSStringFromClass([self class]), _cmd);
    return self;
}

#ifdef PORTING
- (void)encodeWithCoder:(NSCoder *)aCoder;
{
    int i;
    const char *temp;

//	printf("\tSaving %s\n", phoneSymbol);
    [aCoder encodeValuesOfObjCTypes:"**", &phoneSymbol, &comment];

//	printf("\tSaving parameter, meta, and symbolList\n", phoneSymbol);
    [aCoder encodeObject:parameterList];
    [aCoder encodeObject:metaParameterList];
    [aCoder encodeObject:symbolList];

//	printf("\tSaving categoryList\n", phoneSymbol);
    /* Here's the tricky one! */
    i = [categoryList count];

    [aCoder encodeValueOfObjCType:"i" at:&i];
    for(i = 0; i<[categoryList count]; i++)
    {
        temp = [[categoryList objectAtIndex:i] symbol];
        [aCoder encodeValueOfObjCType:"*" at:&temp];
    }
}
#endif

@end
