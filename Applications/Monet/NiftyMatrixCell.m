/*
 *    Filename:	NiftyMatrixCell.m
 *    Created :	Wed Jan  8 23:36:39 1992
 *    Author  :	Vince DeMarco
 *		<vince@whatnxt.cuc.ab.ca>
 *
 * LastEditDate "Fri May 22 01:37:25 1992"
 *
 * _Log: NiftyMatrixCell.m,v $
 * Revision 1.2  2002/12/15 05:05:09  fedor
 * Port to Openstep and GNUstep
 *
 * Revision 1.1  2002/03/21 16:49:47  rao
 * Initial import.
 *
# Revision 2.1  1992/06/10  14:29:07  vince
# drawInside:inView: and setFont: methods are now gone, instead
# the TextObject that is always present in a cell is being used
# to display the textValue of the cell and to toggle the color of
# the text. This is much more efficient than drawing the text
# with PostScript operators.
#
# Revision 2.0  1992/04/08  03:43:23  vince
# Initial-Release
#
 *
 */


// CustomCell.m
// By Jayson Adams, NeXT Developer Support Team
// You may freely copy, distribute and reuse the code in this example.
// NeXT disclaims any warranty of any kind, expressed or implied, as to its
// fitness for any
// particular use.

#import "NiftyMatrixCell.h"

#import <AppKit/AppKit.h>

@implementation NiftyMatrixCell

/* instance methods */

- (id)initTextCell:(NSString *)aString;
{
    if ([super initTextCell:aString] == nil)
        return nil;

    controlFlags.toggleValue = YES;
    controlFlags.locked = NO;
    [self setAlignment:NSLeftTextAlignment]; // Have the text be displayed Left Aligned
    orderTag = 0;

    return self;
}

- (BOOL)toggleValue;
{
    return controlFlags.toggleValue;
}

- (void)setToggleValue:(BOOL)value;
{
    if (controlFlags.locked == NO) {
        controlFlags.toggleValue = value;
    }
}

- (void)toggle;
{
    if (controlFlags.locked == NO) {
        controlFlags.toggleValue = controlFlags.toggleValue ? 0 : 1;
    }
}

- (BOOL)locked;
{
    return controlFlags.locked;
}

- (void)lock;
{
    controlFlags.locked = YES;
}

- (void)unlock;
{
    controlFlags.locked = NO;
}

/* The - drawInside:(const NXRect *)cellFrame inView:controlView method has been
 * Removed it was grossly inefficent. Considering that a Text object will be
 * Present i might as well take advantage of it
 */
- (NSText *)setUpFieldEditorAttributes:(NSText *)textObj;
{
    if (controlFlags.toggleValue) {
        [textObj setTextColor:[NSColor blackColor]];
    } else {
        [textObj setTextColor:[NSColor darkGrayColor]];
    }

    return textObj;
}

- (int)orderTag;
{
    return orderTag;
}

- (void)setOrderTag:(int)newOrderTag;
{
    orderTag = newOrderTag;
}

@end
