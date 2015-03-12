//
//  DConnectSystemProfile.h
//  dConnectManager
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*! 
 @file
 @brief Systemプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>
#import <UIKit/UIKit.h>

/*!
 
 @brief プロファイル名: system。
 */
extern NSString *const DConnectSystemProfileName;


/*!
 @brief インターフェース: device。
 */
extern NSString *const DConnectSystemProfileInterfaceDevice;

/*!
 @brief アトリビュート: wakeup。
 */
extern NSString *const DConnectSystemProfileAttrWakeUp;

/*!
 @brief アトリビュート: keyword。
 */
extern NSString *const DConnectSystemProfileAttrKeyword;
/*!
 
 @brief アトリビュート: events。
 */
extern NSString *const DConnectSystemProfileAttrEvents;

/*!
 @brief パラメータ: supports。
 */
extern NSString *const DConnectSystemProfileParamSupports;

/*!
 @brief パラメータ: plugins。
 */
extern NSString *const DConnectSystemProfileParamPlugins;

/*!
 @brief パラメータ: pluginId。
 */
extern NSString *const DConnectSystemProfileParamPluginId;

/*!
 @brief パラメータ: id。
 */
extern NSString *const DConnectSystemProfileParamId;

/*!
 @brief パラメータ: name。
 */
extern NSString *const DConnectSystemProfileParamName;

@class DConnectSystemProfile;

/*!
 @protocol DConnectSystemProfileDelegate
 @brief System Profileの各APIリクエスト通知用デリゲート。
 
 System Profileの各APIへのリクエスト受信通知を受け取るデリゲート。
 */
@protocol DConnectSystemProfileDelegate <NSObject>
@optional

#pragma mark - Put Methods

/*!
 
 @brief DConnectManager設定キーワード表示リクエストを受け取ったことをデリゲートに通知する。
 
 profileがDConnectManager設定キーワード表示リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 @attention DConnectManager以外で実装する必要はない。
 
 <p>
 [対応するAPI] System Show Keyword API [PUT]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectSystemProfile *)profile didReceivePutKeywordRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response;

#pragma mark - Delete Methods

/*!
 
 @brief イベント一括解除リクエストを受け取ったことをデリゲートに通知する。
 
 profileがイベント一括解除リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] System Events Unregister API [DELETE]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 @param[in] sessionKey セッションキー
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectSystemProfile *)profile didReceiveDeleteEventsRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
      sessionKey:(NSString *)sessionKey;

@end


/*!
 @protocol DConnectSystemProfileDataSource
 @brief Systemプロファイルのデータソース。

 DConnectSystemProfileにシステム情報を提供するデータソース。
 */

@protocol DConnectSystemProfileDataSource <NSObject>
@required

/*!
 @brief データソースにデバイスプラグインのバージョンを要求する。
 
 @param[in] profile プロファイル
 
 @retval NSString* バージョン
 */
- (NSString *) versionOfSystemProfile:(DConnectSystemProfile *)profile;

/*!
 @brief データソースにデバイスプラグインの設定画面用のUIViewControllerを要求する。
 @attention このメソッドはUIスレッドで呼び出される。
 
 @param[in] sender プロファイル
 @param[in] request リクエスト
 
 @retval UIViewController* 設定画面用のUIViewController
 */
- (UIViewController *) profile:(DConnectSystemProfile *)sender
         settingPageForRequest:(DConnectRequestMessage *)request;

@end

/*!
 @class DConnectSystemProfile
 @brief Systemプロファイル。
 
 System Profileの各APIへのリクエストを受信する。
 受信したリクエストは各API毎にデリゲートに通知される。
 */
@interface DConnectSystemProfile : DConnectProfile

/*!
@brief DConnectSystemProfileのデリゲートオブジェクト。

デリゲートは @link DConnectSystemProfileDelegate @endlink を実装しなくてはならない。
デリゲートはretainされない。
*/
@property (nonatomic, weak) id<DConnectSystemProfileDelegate> delegate;

/*!
 @brief DConnectSystemProfileのデータソースオブジェクト。
 
 データソースは @link DConnectSystemProfileDataSource @endlink を実装しなくてはならない。
 データソースはretainされない。
 */
@property (nonatomic, weak) id<DConnectSystemProfileDataSource> dataSource;

#pragma mark - Setter

/*!
 @brief メッセージにサポートしているI/Fの一覧を格納する。
 
 @param[in] supports サポートしているI/F一覧
 @param[in,out] message I/Fの一覧を格納するメッセージ
 */
+ (void) setSupports:(DConnectArray *)supports target:(DConnectMessage *)message;

/*!
 @brief メッセージにサポートしているデバイスプラグインの一覧を格納する。
 
 @param[in] plugins サポートしているデバイスプラグイン一覧
 @param[in,out] message デバイスプラグインの一覧を格納するメッセージ
 */
+ (void) setPlugins:(DConnectArray *)plugins target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグインIDを格納する。
 
 @param[in] pluginId デバイスプラグインID
 @param[in,out] message デバイスプラグインIDを格納するメッセージ
 */
+ (void) setId:(NSString *)pluginId target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグイン名を格納する。
 
 @param[in] name デバイスプラグイン名
 @param[in,out] message デバイスプラグイン名を格納するメッセージ
 */
+ (void) setName:(NSString *)name target:(DConnectMessage *)message;

#pragma mark - Getter

/*!
 @brief リクエストからpluginIdを取得する。
 
 @param[in] request リクエストパラメータ
 @retval NSString* デバイスプラグインID
 @retval nil pluginIdが指定されていない場合
 */
+ (NSString *) pluginIdFromRequest:(DConnectMessage *)request;

@end
