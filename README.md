# Sonect Shop SDK for iOS [PRELIMINARY]

In this document we will go through the necessary steps to integrate
Sonect Shop SDK in your iOS app. 

## Installation: 

Via dependency managers:
- Cocoapods: `pod 'sonect-shop-sdk-ios'`
- Carthage: `github "sonect/sonect-shop-sdk-ios"`
- Manual

Sonect Shop SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

Minimum version: iOS 10.0+ 

The main entry point to the SDK is `SNCSonectShop` object. To present the Sonect view controller, you have to obtain the SDK token, the user ID and the signature, which **must** be calculated on your bank's serverside for security reasons.  

## Obj-C

### Simple SDK Integration 
```
SNCShopCredentials *credentials = [[SNCShopCredentials alloc] initWithSdkToken:_SHOP_SDK_TOKEN_
								    merchantId:_YOUR_MERCHANT_ID_
							       	      password:_YOUR_PASSWORD_];
//Optionally assign a device id if you have multiple devices
credentials.deviceId = @"YOUR_DEVICE_ID";

//Create a SonectShopConfiguration.plist, alternatively use initWithContentsOfFile:
SNCShopConfiguration *configuration = [SNCShopConfiguration defaultConfiguration];

[SNCSonectShop presentWithCredentials:credentials
                        configuration:configuration
             presentingViewController:self.viewController];
```

### Configuration file

In order to configure the SDK, create a `SonectShopConfiguration.plist` file, and fill out the mandatory fields. You can load the configuration by using the `SNCShopConfiguration` object. A sample plist file might look like this, for more info consult the `SNCShopConfiguration` interface documentation. 

Sample `SonectShopConfiguration.plist` values: 
```
<dict>
	<key>SonectAlpha2CountryCode</key>
	<string>ch</string>
	<key>SonectCurrency</key>
	<string>CHF</string>
	<key>SonectAllowedCountryCodes</key>
	<array>
		<integer>41</integer>
		<integer>1</integer>
	</array>
</dict>
```
