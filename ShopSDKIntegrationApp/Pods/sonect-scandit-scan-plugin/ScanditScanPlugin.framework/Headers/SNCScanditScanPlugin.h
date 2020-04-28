//
//  SNCScanditScanPlugin.h
//  ScanditScanPlugin
//
//  Created by Marko Hlebar on 18/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

//TODO: We can't use this from the public interface as it breaks compilation in the project where SonectShop.framework is added
//#import <SonectShop/SNCScanCodePlugin.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCScanditScanPlugin : NSObject

/// Initializes the plugin with a license key.
/// @param licenseKey a valid Scandit license key.
- (instancetype)initWithLicenseKey:(NSString *)licenseKey;

@end

NS_ASSUME_NONNULL_END
