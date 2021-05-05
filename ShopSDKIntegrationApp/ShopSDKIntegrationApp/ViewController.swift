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
        let credentials = SNCShopCredentials(sdkToken: "N2QwYmQ2ZjAtODdmNC0xMWViLTg0NTUtYmI5MmQ4YjgzNjk1OjFhOTE4OWY2NDE0NDM1YTNiZjg0Y2U5Njc3ZDc0OTQ1ZmI2OTM1ZWVhMjZkYzg2MzQwYjg1MmQzZjEzYzIxYWY=",
                                             merchantId: "Merchant",
                                             signature: "3vZGmZqYnZfUDUzC0em/SpdRPLXM99Z/+vZ0C1hm+lM=",
                                             deviceId: "1")
        SNCSonectShop.scanCodePlugin = SNCScanditScanPlugin(licenseKey: "_SCANDIT_KEY_")
        SNCSonectShop.kycProviderPlugin = IdenfyKycProviderPlugin()
        SNCSonectShop.addressAutocompletionPlugin = SNCGoogleAddressAutocompletionPlugin(apiKey: "_GOOGLE_API_KEY_")
        SNCSonectShop.present(with: credentials, configuration: configuration, presenting: self)
    }
}
