Pod::Spec.new do |s|
  s.name             = 'EMapgoSDK'
  s.version          = '1.1.0-beta'
  s.summary          = 'EMapgoSDK pod Use.'

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

  #你的SDK路径
   s.vendored_frameworks = 'EMapgo/EMapgo.framework'

   s.module_name = 'EMapgo'

end
