#
# Be sure to run `pod lib lint TGSDKText.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'EMapgoSDK'
  s.version          = '1.0.0'
  s.summary          = 'EMapgoSDK pod Use.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: 易图通地图iOS SDK基于iOS 9.0。通过调用地图SDK接口，您可以访问易图通地图服务和数据。
                       DESC

  s.homepage         = 'https://github.com/xiaoleiiOS/EMapgoSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'xiaolei.wang@emapgo.com.cn' => 'xiaolei.wang@emapgo.com.cn' }
  s.source           = { :git => 'https://github.com/xiaoleiiOS/EMapgoSDK.git', :tag => s.version.to_s }#你的仓库地址，不能用SSH地址
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.requires_arc = true # 是否启用ARC


#s.frameworks = 'UIKit', 'Foundation'
  # s.dependency 'AFNetworking', '~> 2.3'

#s.resource = 'EMapgoSDK/Assets/*.lproj', 'TGameSDK/Assets/TGameFramework.bundle'

#  s.vendored_frameworks = 'TGameSDKTest.framework'
  #你的SDK路径
   s.vendored_frameworks = 'EMapgo/*.framework'


end
