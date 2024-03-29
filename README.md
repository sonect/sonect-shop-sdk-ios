# Sonect Shop SDK for iOS

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

## Simple SDK Integration 

### Swift
```swift
//Some of the credentials can be aquired from Sonect panel, others are merchant specific
let credentials = SNCShopCredentials(sdkToken: _SHOP_SDK_TOKEN_, merchantId:_YOUR_MERCHANT_ID_, signature:_PARTNER_SIGNATURE_,  deviceId:_YOUR_DEVICE_ID_)

//Create configuration using SonectShopConfiguration.plist, alternatively use SNCShopConfiguration(contentsOfFile:):
let configuration = SNCShopConfiguration.default()

//In order to scan the barcodes, you need to set your preferred scanning plugin, or implement your own
let scanPlugin = MyScanCodePlugin()
SNCSonectShop.scanCodePlugin = scanPlugin

//In order to check user's KYC, use a Idenfy KYC plugin or implement your own.  
let kycPlugin = MyKycProviderPlugin()
SNCSonectShop.kycProviderPlugin = kycPlugin

//In order to add address autocompletion use Google Autocompletion, or implement your own.
let addressAutocompletionPlugin = MyAddressAutocompletionPlugin()
SNCSonectShop.addressAutocompletionPlugin = addressAutocompletionPlugin

//Present the shop interface on top of your app. 
SNCSonectShop.present(with: credentials, configuration: configuration, presenting: viewController)

```

### Obj-C
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

## Barcode scanning

The Sonect Shop SDK allows you to use your barcode scanning SDK, by implementing a simple `SNCScanCodePlugin` protocol, and plugging it in the Sonect Shop SDK.

### Swift
```swift
let scanPlugin = MyScanCodePlugin()
SNCSonectShop.scanCodePlugin = scanPlugin
```

### Obj-C
```objc
id <SNCScanCodePlugin> scanPlugin = [MyScanCodePlugin new];
SNCSonectShop.scanCodePlugin = scanPlugin;
```

Optimally, for best barcode and QR code scanning experience, Sonect has partnered with Scandit, so you can also use the [Scandit Plugin](https://github.com/sonect/sonect-scandit-scan-plugin). Sonect will provide additional details for integration.

## KYC Check

The Sonect Shop SDK allows you to use Idenfy as the KYC check provider. Integrate the [Idenfy KYC Plugin](https://github.com/sonect/sonect-idenfy-kyc-plugin) as described in the repository README page to get the benefits of Idenfy scanning. Sonect will provide additional details for integration.

## Address Autocompletion

With Sonect Shop SDK allows you can use Google autocompletion as the default address autocompletion plugin. Integrate the [Sonect Google Address Autocompletion Plugin](https://github.com/sonect/sonect-google-address-autocompletion-plugin) as described in the repository README page. If your company does not allow the usage of Google API-s you can roll your own autocomplete solution by implementing the `SNCAddressAutocompletionPlugin` protocol, and assigning it to the Sonect Shop SDK like so 

### Swift
```swift
let addressAutocompletionPlugin = MyAddressAutocompletionPlugin()
SNCSonectShop.addressAutocompletionPlugin = addressAutocompletionPlugin
```

### Obj-C
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
	<key>SonectShouldShowPaymentId</key>
	<true/>
</dict>
```

## Passing arbitrary shop attributes

If you need to pass arbitrary shop attributes i.e. a VAT number, then you can use Shop Attributes structure to do so. 

### Swift
```swift
let configuration = ... //YOUR_CONFIGURATION
var attributes = SNCShopAttributes()
attributes = attributes.addingData({"VAT":"123456789"})
configuration.shopAttributes = attributes
```

### Obj-C
```objc
SNCShopConfiguration *configuration = ... //YOUR_CONFIGURATION
SNCShopAttributes *attributes = [SNCShopAttributes attributesByAddingData: @{ @"VAT": @"123456789"}];
configuration.shopAttributes = attributes;
```

## Events

If you have set up event handler, for example:

```swift
SNCSonectShop.eventHandler = MySonectShopEventHandler()
```

In the following method:
```swift
func sonectShop(_ shop: SNCSonectShop, handleEvent event: String, withParameters parameters: [AnyHashable : Any]?) {
}
```
your event handler class will receive events when certain actions happen in Sonect Shop SDK.

Event `shop_terms_and_condition_signed` is send when user agrees to Terms and Conditions and taps "Continue" button on following screen:

![terms_and_conditions_toaster.png](/terms_and_conditions_toaster.png)

Note: This screen could be disabled by your partner configuration on our admin panel, which would result in this event not firing.


Event `shop_onboarding_completed` is send when user has completed onboarding process and is presented with this screen:

![registration_completed_screen.png](/registration_completed_screen.png)

## Themes

Sonect SDK supports theming colors and fonts to allow you to customize the SDK, so that it looks and feels right when embedded in your app. To apply a theme, you need to create a new `SNCTheme` object and apply a theme like in the following example. 

### Swift
```swift
let theme = SNCTheme()
theme.type = .dark
theme.fontName = "Arial"
theme.boldFontName = "Arial-Bold"
theme.detailColor1 = .yellow
theme.detailColor2 = .yellow
theme.detailColor3 = .yellow
theme.detailColor4 = .yellow
theme.detailColor5 = .yellow
theme.navigationBarTintColor = .yellow
theme.navigationBarTitleImage = UIImage(named: "rba")
theme.selectedAmountColors = [theme1.detailColor1!, theme1.detailColor2!, theme1.detailColor3!, theme1.detailColor4!]
```

### Obj-C
```objc
SNCTheme *theme = [SNCTheme new];
theme.type = SNCThemeTypeLight;
theme.fontName = "Futura-Medium";
theme.boldFontName = "Futura-CondensedExtraBold";
theme.detailColor1 = UIColor.yellowColor;
theme.detailColor2 = UIColor.yellowColor;
theme.detailColor3 = UIColor.yellowColor;
theme.detailColor4 = UIColor.yellowColor;
theme.detailColor5 = UIColor.yellowColor;
theme.navigationBarTintColor = UIColor.yellowColor;
theme.navigationBarTitleImage = [UIImage imageNamed:@"rba"];
[theme set];
```

![](https://github.com/sonect/sonect-shop-sdk-ios/blob/master/misc/shop_theme_samples.png)
