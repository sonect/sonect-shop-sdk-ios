# Sonect Shop SDK for iOS [PRELIMINARY]

In this document we will go through the necessary steps to integrate
Sonect Shop SDK in your iOS app. 

Contact support@sonect.ch if additional info is needed.


## Installation: 

Via dependency managers:
- Cocoapods: `pod 'sonect-shop-sdk-ios'` [Installation guide](https://github.com/sonect/sonect-shop-sdk-ios/blob/master/install_with_cocoapods.md)
- Carthage: `github "sonect/sonect-shop-sdk-ios"`
- Manual

Sonect Shop SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

Minimum version: iOS 9.0+ 

The main entry point to the SDK is `SNCSonectShop` object. To present the Sonect view controller, you have to obtain the SDK token, the user ID and the signature, which **must** be calculated on your bank's serverside for security reasons.  

## Obj-C

### Simple SDK Integration 
```objc
SNCShopCredentials *credentials = [[SNCShopCredentials alloc] initWithSdkToken:_SHOP_SDK_TOKEN_
								    merchantId:_YOUR_MERCHANT_ID_
							       	      deviceId:_YOUR_DEVICE_ID_];

//Create a SonectShopConfiguration.plist, alternatively use initWithContentsOfFile:
SNCShopConfiguration *configuration = [SNCShopConfiguration defaultConfiguration];

//In order to scan the barcodes, you need to set your preferred scanning plugin, or implement your own. 
id <SNCScanCodePlugin> scanPlugin = [MyScanCodePlugin new];
SNCSonectShop.scanCodePlugin = scanPlugin;

//In order to check user's KYC, use a Idenfy KYC plugin or implement your own.  
id <SNCKycProviderPlugin> kycPlugin = [MyKycProviderPlugin new];
SNCSonectShop.kycProviderPlugin = kycPlugin;

//In order to add address autocompletion use Google Autocompletion, or implemnent your own.
id <SNCAddressAutocompletionPlugin> plugin = [MyAddressAutocompletionPlugin new];
SNCSonectShop.addressAutocompletionPlugin = plugin;

//Present the shop interface on top of your app. 
[SNCSonectShop presentWithCredentials:credentials
                        configuration:configuration
             presentingViewController:self.viewController];
```

### Barcode scanning

The Sonect Shop SDK allows you to use your barcode scanning SDK, by implementing a simple `SNCScanCodePlugin` protocol, and plugging it in the Sonect Shop SDK.
```objc
id <SNCScanCodePlugin> scanPlugin = [MyScanCodePlugin new];
SNCSonectShop.scanCodePlugin = scanPlugin;
```

Optimally, for best barcode and QR code scanning experience, Sonect has partnered with Scandit, so you can also use the [Scandit Plugin](https://github.com/sonect/sonect-scandit-scan-plugin). Sonect will provide additional details for integration.

### KYC Check

The Sonect Shop SDK allows you to use Idenfy as the KYC check provider. Integrate the [Idenfy KYC Plugin](https://github.com/sonect/sonect-idenfy-kyc-plugin) as described in the repository README page to get the benefits of Idenfy scanning. Sonect will provide additional details for integration.

### Address Autocompletion

With Sonect Shop SDK allows you can use Google autocompletion as the default address autocompletion plugin. Integrate the [Sonect Google Address Autocompletion Plugin](https://github.com/sonect/sonect-google-address-autocompletion-plugin) as described in the repository README page. If your company does not allow the usage of Google API-s you can roll your own autocomplete solution by implementing the `SNCAddressAutocompletionPlugin` protocol, and assigning it to the Sonect Shop SDK like so 

```objc
id <SNCAddressAutocompletionPlugin> plugin = [MyAddressAutocompletionPlugin new];
SNCSonectShop.addressAutocompletionPlugin = plugin;
```

### Configuration file

In order to configure the SDK, create a `SonectShopConfiguration.plist` file, and fill out the mandatory fields. You can load the configuration by using the `SNCShopConfiguration` object. A sample plist file might look like this, for more info consult the `SNCShopConfiguration` interface documentation. 

Sample `SonectShopConfiguration.plist` values: 
```xml
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
