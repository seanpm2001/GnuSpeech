//  This file is part of Gnuspeech, an extensible, text-to-speech package, based on real-time, articulatory, speech-synthesis-by-rules. 
//  Copyright (c) 1991-2012 David R. Hill, Leonard Manzara, Craig Schock

#import "MMFormulaNode.h"

@class MMSymbol;

#define RULEDURATION    (-2)
#define BEAT		(-3)
#define MARK1		(-4)
#define MARK2		(-5)
#define MARK3		(-6)
#define TEMPO0		(-7)
#define TEMPO1		(-8)
#define TEMPO2		(-9)
#define TEMPO3		(-10)


@interface MMFormulaTerminal : MMFormulaNode
{
    MMSymbol *symbol;
    double value;
    NSInteger whichPhone; // TODO (2004-03-10): Rename this
}

- (id)init;
- (void)dealloc;

- (MMSymbol *)symbol;
- (void)setSymbol:(MMSymbol *)newSymbol;

- (double)value;
- (void)setValue:(double)newValue;

- (NSInteger)whichPhone;
- (void)setWhichPhone:(NSInteger)newValue;

// Methods overridden from MMFormulaNode
- (NSUInteger)precedence;

- (double)evaluate:(MMFRuleSymbols *)ruleSymbols postures:(NSArray *)postures tempos:(double *)tempos;

- (NSInteger)maxPhone;

- (void)expressionString:(NSMutableString *)resultString;

@end
