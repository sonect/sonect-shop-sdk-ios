# Installing Sonect SDK with Cocoapods

Sonect SDK has dependencies that are not available via dependency managers, so [contact Sonect](contact@sonect.ch), to 
obtain those dependencies, and respective license keys. You will get an `External.zip` file. 

In your `Podfile` add the following pods:

```
pod 'sonect-shop-sdk-ios'
pod 'sonect-scandit-scan-plugin'
pod 'sonect-idenfy-kyc-plugin'
pod 'sonect-google-address-autocompletion-plugin'
pod 'iDenfySDK/iDenfyLiveness'
```

and run `pod update`

Unzip the `External.zip` file and place the directory inside your project folder, 
then add the External directory to your Xcode project. 

![](https://github.com/sonect/sonect-shop-sdk-ios/blob/master/misc/external1.png)

Next go to `Build Phases` in Xcode, and add the following libraries to 
`Link Binary With Libraries`

```
libz.tbd 
libiconv.tbd
MediaPlayer.framework
libc++.tbd
ScanditBarcodeScanner.framework
```

![](https://github.com/sonect/sonect-shop-sdk-ios/blob/master/misc/link_binaries.png)

Build. 
