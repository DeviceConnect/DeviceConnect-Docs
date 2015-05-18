//
//  DConnectServiceDiscoveryProfile.h
//  dConnectManager
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*! 
 @file
 @brief Service Discoveryプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>
#import <DConnectSDK/DConnectProfileProvider.h>

/*!
 @brief プロファイル名: servicediscovery。
 */
extern NSString *const DConnectServiceDiscoveryProfileName;

/*!
 @brief アトリビュート: onservicechange。
 */
extern NSString *const DConnectServiceDiscoveryProfileAttrOnServiceChange;

/*!
 @brief パラメータ: networkService。
 */

extern NSString *const DConnectServiceDiscoveryProfileParamNetworkService;

/*!
 @brief パラメータ: services。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamServices;

/*!
 @brief パラメータ: state。
 */

extern NSString *const DConnectServiceDiscoveryProfileParamState;

/*!
 @brief パラメータ: id。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamId;

/*!
 @brief パラメータ: name。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamName;

/*!
 @brief パラメータ: type。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamType;

/*!
 @brief パラメータ: online。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamOnline;

/*!
 @brief パラメータ: config。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamConfig;

/*!
 @brief パラメータ: scopes。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamScopes;

/*!
 @brief パラメータ: manufacturer。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamManufacturer;

/*!
 @brief パラメータ: version。
 */
extern NSString *const DConnectServiceDiscoveryProfileParamVersion;

/*!
 @brief ネットワークタイプ: unknown。
 */
extern NSString *const DConnectServiceDiscoveryProfileNetworkTypeUnknown;
/*!
 @brief ネットワークタイプ: wifi。
 */
extern NSString *const DConnectServiceDiscoveryProfileNetworkTypeWiFi;
/*!
 @brief ネットワークタイプ: bluetooth。
 */
extern NSString *const DConnectServiceDiscoveryProfileNetworkTypeBluetooth;
/*!
 @brief ネットワークタイプ: nfc。
 */
extern NSString *const DConnectServiceDiscoveryProfileNetworkTypeNFC;
/*!
 @brief ネットワークタイプ: ble。
 */
extern NSString *const DConnectServiceDiscoveryProfileNetworkTypeBLE;

@class DConnectServiceDiscoveryProfile;

/*!
 @protocol DConnectServiceDiscoveryProfileDelegate
 @brief Network Service Dicovery Profileの各APIリクエスト通知用デリゲート。
 
 Network Service Dicovery Profileの各APIへのリクエスト受信通知を受け取るデリゲート。
 */
@protocol DConnectServiceDiscoveryProfileDelegate <NSObject>
@optional

#pragma mark - Get Methods

/*!
 
 @brief 接続されているデバイス一覧の取得リクエストを受け取ったことをデリゲートに通知する。
 
 profileが接続されているデバイス一覧の取得リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Service Discovery API [GET]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectServiceDiscoveryProfile *)profile didReceiveGetServicesRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response;

#pragma mark - Put Methods

/*!
 
 @brief onservicechangeイベント登録リクエストを受け取ったことをデリゲートに通知する。
 
 profileがonservicechangeイベント登録リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Service Discovery Status Change Event API [PUT]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 @param[in] serviceId サービスID
 @param[in] sessionKey セッションキー
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectServiceDiscoveryProfile *)profile didReceivePutOnServiceChangeRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
        serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

#pragma mark - Delete Methods

/*!
 
 @brief onservicechangeイベント解除リクエストを受け取ったことをデリゲートに通知する。
 
 profileがonservicechangeイベント解除リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Service Discovery Status Change Event API [DELETE]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 @param[in] serviceId サービスID
 @param[in] sessionKey セッションキー
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectServiceDiscoveryProfile *)profile didReceiveDeleteOnServiceChangeRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
        serviceId:(NSString *)serviceId
      sessionKey:(NSString *)sessionKey;

@end

/*!
 @class DConnectServiceDiscoveryProfile
 @brief ServiceDiscovery プロファイル。
 
 Service Discovery Profileの各APIへのリクエストを受信する。
 受信したリクエストは各API毎にデリゲートに通知される。
 */
@interface DConnectServiceDiscoveryProfile : DConnectProfile

/*!
 @brief DConnectServiceDiscoveryProfileのデリゲートオブジェクト。
 
 デリゲートは @link DConnectServiceDiscoveryProfileDelegate @endlink を実装しなくてはならない。
 デリゲートはretainされない。
 */
@property (nonatomic, weak) id<DConnectServiceDiscoveryProfileDelegate> delegate;

#pragma mark - Setter

/*!
 @brief メッセージにデバイス一覧を設定する。
 
 @param[in] services デバイス一覧
 @param[in,out] message デバイス一覧を格納するメッセージ
 */
+ (void) setServices:(DConnectArray *)services target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイス情報を設定する。
 
 @param[in] networkService デバイス情報
 @param[in,out] message デバイス情報を格納するメッセージ
 */
+ (void) setNetworkService:(DConnectMessage *)networkService target:(DConnectMessage *)message;

/*!
 @brief メッセージにサービスIDを設定する。
 
 @param[in] id サービスID
 @param[in,out] message サービスIDを格納するメッセージ
 */
+ (void) setId:(NSString *)id target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイス名を設定する。
 
 @param[in] name デバイス名
 @param[in,out] message デバイス名を格納するメッセージ
 */
+ (void) setName:(NSString *)name target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスのネットワークタイプを設定する。
 
 @param[in] type デバイスのネットワークタイプ
 @param[in,out] message デバイスのネットワークタイプを格納するメッセージ
 */
+ (void) setType:(NSString *)type target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスのオンライン状態を設定する。
 
 @param[in] online オンライン: YES、 オフライン: NO
 @param[in,out] message デバイスのオンライン状態を格納するメッセージ
 */
+ (void) setOnline:(BOOL)online target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスの設定情報を設定する。
 
 @param[in] config 設定情報文字列
 @param[in,out] message デバイスの設定情報を格納するメッセージ
 */
+ (void) setConfig:(NSString *)config target:(DConnectMessage *)message;

/*!
 @brief メッセージにサポートするプロファイル名の配列を設定する。
 
 @param[in, out] message デバイスの設定情報を格納するメッセージ
 @param[in] プロファイルプロバイダー
 */
+ (void) setScopesWithProvider:(id<DConnectProfileProvider>)provider
                        target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスの接続状態を設定する。
 
 @param[in] state 接続状態
 @param[in,out] message デバイスの接続状態を格納するメッセージ
 */
+ (void) setState:(BOOL)state target:(DConnectMessage *)message;

@end
