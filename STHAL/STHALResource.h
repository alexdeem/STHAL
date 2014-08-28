//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
//  Copyright (c) 2014 Scott Talbot.

#import <Foundation/Foundation.h>


@protocol STHALLinks;
@protocol STHALEmbeddedResources;
@protocol STHALResource <NSObject>
@property (nonatomic,strong,readonly) id<STHALLinks> links;
@property (nonatomic,copy,readonly) NSDictionary *payload;
@property (nonatomic,strong,readonly) id<STHALEmbeddedResources> embeddedResources;
@end

@protocol STHALLink;
@protocol STHALLinks <NSObject>
@property (nonatomic,copy,readonly) NSArray *relationNames;
- (id<STHALLink>)linkForRelationNamed:(NSString *)name;
- (NSArray *)linksForRelationNamed:(NSString *)name;
- (id)objectForKeyedSubscript:(NSString *)name;
@end

@protocol STHALLink <NSObject>
@property (nonatomic,copy,readonly) NSString *name;
@property (nonatomic,copy,readonly) NSString *type;
@property (nonatomic,copy,readonly) NSURL *url;
@property (nonatomic,copy,readonly) NSArray *templateVariableKeys;
- (NSURL *)urlWithVariables:(NSDictionary *)variables;
@property (nonatomic,copy,readonly) NSURL *deprecation;
@end

@protocol STHALEmbeddedResources <NSObject>
@property (nonatomic,copy,readonly) NSArray *resourceNames;
- (id<STHALResource>)resourceNamed:(NSString *)name;
- (NSArray *)resourcesNamed:(NSString *)name;
- (id)objectForKeyedSubscript:(NSString *)name;
@end


@interface STHALResource : NSObject<STHALResource>
- (id)initWithDictionary:(NSDictionary *)dict baseURL:(NSURL *)baseURL;
@property (nonatomic,strong,readonly) id<STHALLinks> links;
@property (nonatomic,copy,readonly) NSDictionary *payload;
@property (nonatomic,strong,readonly) id<STHALEmbeddedResources> embeddedResources;
@end