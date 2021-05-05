//
//  SNCScanditScanPlugin.h
//  ScanditScanPlugin
//
//  Created by Marko Hlebar on 18/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//We can't use this from the public interface as it breaks compilation in the project where SonectShop.framework is added
//#import <SonectShop/SNCScanCodePlugin.h>

//Marking a forward protocol helps fix the problem with imports.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
@protocol SNCScanCodePlugin;
@interface SNCScanditScanPlugin : NSObject <SNCScanCodePlugin>
#pragma clang diagnostic pop

/// Initializes the plugin with a license key.
/// @param licenseKey a valid Scandit license key.
- (instancetype)initWithLicenseKey:(NSString *)licenseKey;

@end

NS_ASSUME_NONNULL_END
