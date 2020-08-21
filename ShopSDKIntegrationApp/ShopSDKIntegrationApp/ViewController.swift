//
//  ViewController.swift
//  ShopSDKIntegrationApp
//
//  Created by Marko Hlebar on 13/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import SonectShop
import sonect_idenfy_kyc_plugin
import GoogleAddressAutocompletionPlugin
import ScanditScanPlugin

class ViewController: UIViewController {

    @IBAction func openSdk(_ sender: Any) {
        let configuration = SNCShopConfiguration.default()
        let credentials = SNCShopCredentials(sdkToken: "_SDK_TOKEN_",
                                             merchantId: "_MERCHANT_ID_",
                                             signature: "_SIGNATURE_",
                                             deviceId: "_DEVICE_ID")
        SNCSonectShop.scanCodePlugin = SNCScanditScanPlugin(licenseKey: "_SCANDIT_KEY_")
        SNCSonectShop.kycProviderPlugin = IdenfyKycProviderPlugin()
        SNCSonectShop.addressAutocompletionPlugin = SNCGoogleAddressAutocompletionPlugin(apiKey: "_GOOGLE_API_KEY_")
        SNCSonectShop.present(with: credentials, configuration: configuration, presenting: self)
    }
}
