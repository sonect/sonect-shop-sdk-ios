//
//  SNCModel.h
//  Sonect
//
//  Created by Marko Hlebar on 01/07/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SNCModel <NSObject>
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
+ (BOOL)snc_isValidDictionary:(NSDictionary *)dictionary error:(NSError **)error;
@end

@interface NSObject (SNCModel)
+ (BOOL)snc_isValidDictionary:(NSDictionary *)dictionary error:(NSError **)error;
+ (NSDictionary<NSString *, Class> *)snc_requiredKeys;
+ (BOOL)snc_validateValue:(id)value forKey:(NSString *)key error:(NSError **)error;
@end

NS_ASSUME_NONNULL_END
