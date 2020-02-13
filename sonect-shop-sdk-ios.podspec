Pod::Spec.new do |spec|

  spec.name         = "sonect-shop-sdk-ios"
  spec.version      = "0.1.3"
  spec.summary      = "Sonect Shop SDK"
  spec.description  = <<-DESC
  This is the Sonect Shop SDK public podspec. 
                   DESC

  spec.homepage     = "https://github.com/sonect/sonect-shop-sdk-ios"
  spec.license      = { :type => "Sonect Closed Source", :text => <<-LICENSE
                    Copyright (C) Sonect AG - All Rights Reserved
                    Unauthorized copying of this file, and the Sonect SDK via any medium is strictly prohibited
                    Proprietary and confidential
                    Sonect, January 2020. 
                    LICENSE
               }
  spec.author             = { "sonect" => "marko.hlebar@sonect.ch" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :http => "https://github.com/sonect/sonect-sdk-ios/releases/download/#{spec.version}/SonectShopSDK_Cocoapods.framework.zip" }
  spec.ios.vendored_frameworks = 'SonectShop.framework'

end