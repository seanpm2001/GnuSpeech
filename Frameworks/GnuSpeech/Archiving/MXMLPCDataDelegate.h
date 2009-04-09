////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2004 Steve Nygard.  All rights reserved.
//  
//  Contributors: Steve Nygard
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////
//
//  This file is part of SNFoundation, a personal collection of Foundation 
//  extensions. Copyright (C) 2004 Steve Nygard.  All rights reserved.
//
//  MXMLPCDataDelegate.h
//  GnuSpeech
//
//  Created by Steve Nygard in 2004
//
//  Version: 0.8
//
////////////////////////////////////////////////////////////////////////////////

#import <Foundation/NSObject.h>

@class NSMutableDictionary, NSMutableString, NSXMLParser;

@interface MXMLPCDataDelegate : NSObject
{
    NSString *elementName;
    id delegate;
    SEL setSelector;

    NSMutableString *string;
}

- (id)initWithElementName:(NSString *)anElementName delegate:(id)aDelegate setSelector:(SEL)aSetSelector;
- (void)dealloc;

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)aString;

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)anElementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName;

@end
