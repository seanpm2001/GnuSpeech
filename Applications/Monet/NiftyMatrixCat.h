/*
 *    Filename:	NiftyMatrixCat.h
 *    Created :	Wed Jan  8 23:35:20 1992
 *    Author  :	Vince DeMarco
 *		<vince@whatnxt.cuc.ab.ca>
 *
 * LastEditDate "Tue Apr  7 21:36:31 1992"
 *
 * _Log: NiftyMatrixCat.h,v $
 * Revision 1.2  2002/12/15 05:05:09  fedor
 * Port to Openstep and GNUstep
 *
 * Revision 1.1  2002/03/21 16:49:47  rao
 * Initial import.
 *
 * Revision 2.0  1992/04/08  03:43:23  vince
 * Initial-Release
 *
 *
 */

#import "NiftyMatrix.h"

@interface NiftyMatrix (NiftyMatrixCat)

- (void)removeCellWithStringValue:(NSString *)stringValue;
- (void)removeAllCells;
- (void)insertCellWithStringValue:(NSString *)stringValue;
- (void)insertCellWithStringValue:(NSString *)stringValue withTag:(int)tag;
- (void)grayAllCells;
- (void)ungrayAllCells;
- (NSCell *)findCellNamed:(NSString *)stringValue;

@end
