//
//  ViewController.swift
//  ShopSDKIntegrationApp
//
//  Created by Marko Hlebar on 13/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import SonectShop

// TODO: Implement your own scanner
class ScanPlugin: NSObject, SNCScanCodePlugin {
    func viewController() -> UIViewController {
        return UIViewController()
    }
    
    func scan(_ handler: @escaping SNCScanCodeResultHandler) {
    }
    
    func stop() {
    }
}

class ViewController: UIViewController {

    @IBAction func openSdk(_ sender: Any) {
        let configuration = SNCConfiguration.default()
        
        // TODO: Obtain an SDK token from a web service
        let sdkToken = "_SDK_TOKEN_"
        let credentials = SNCShopCredentials(sdkToken: sdkToken)
        let scanPlugin = ScanPlugin()
        SNCSonectShop.scanCodePlugin = scanPlugin
        SNCSonectShop.present(with: credentials, configuration: configuration, presenting: self)
    }
}

