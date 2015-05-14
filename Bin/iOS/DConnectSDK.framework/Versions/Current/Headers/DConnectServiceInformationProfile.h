//
//  DConnectServiceInformationProfile.h
//  DConnectSDK
//
//  Copyright (c) 2015 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//
//
//  DConnectServiceInformationProfile.h
//  dConnectManager
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*!
 @file
 @brief ServiceInformationプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>
#import <UIKit/UIKit.h>

/*!
 
 @brief プロファイル名: system。
 */
extern NSString *const DConnectServiceInformationProfileName;

/*!
 @brief パラメータ: supports。
 */
extern NSString *const DConnectServiceInformationProfileParamSupports;

/*!
 @brief パラメータ: connect。
 */
extern NSString *const DConnectServiceInformationProfileParamConnect;

/*!
 @brief パラメータ: wifi。
 */
extern NSString *const DConnectServiceInformationProfileParamWiFi;

/*!
 @brief パラメータ: bluetooth。
 */
extern NSString *const DConnectServiceInformationProfileParamBluetooth;

/*!
 @brief パラメータ: nfc。
 */
extern NSString *const DConnectServiceInformationProfileParamNFC;

/*!
 @brief パラメータ: ble。
 */
extern NSString *const DConnectServiceInformationProfileParamBLE;

/*!
 @enum DConnectServiceInformationProfileConnectState
 @brief デバイスの接続状態定数。
 */
typedef NS_ENUM(NSInteger, DConnectServiceInformationProfileConnectState) {
    DConnectServiceInformationProfileConnectStateNone = 0,  /*!< 非対応 */
    DConnectServiceInformationProfileConnectStateOn,        /*!< 接続ON */
    DConnectServiceInformationProfileConnectStateOff        /*!< 接続OFF */
};

@class DConnectServiceInformationProfile;

/*!
 @protocol DConnectServiceInformationProfileDelegate
 @brief Service Information Profileの各APIリクエスト通知用デリゲート。
 
 System Profileの各APIへのリクエスト受信通知を受け取るデリゲート。
 */
@protocol DConnectServiceInformationProfileDelegate <NSObject>
@optional

#pragma mark - Get Methods

/*!
 
 @brief 周辺機器のシステム情報取得リクエストを受け取ったことをデリゲートに通知する。
 
 profileが周辺機器のシステム情報取得リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Service Information API [GET]
 </p>
 
 @param[in] profile プロファイル
 @param[in] request リクエストパラメータ
 @param[in,out] response レスポンスパラメータ
 @param[in] serviceId サービスID
 
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL) profile:(DConnectServiceInformationProfile *)profile didReceiveGetInformationRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

@end


/*!
 @protocol DConnectServiceInformationProfileDataSource
 @brief ServiceInformationプロファイルのデータソース。
 
 DConnectServiceInformationProfileにシステム情報を提供するデータソース。
 */

@protocol DConnectServiceInformationProfileDataSource <NSObject>
@optional

/*!
 
 @brief データソースにWiFiの接続状態を要求する。
 
 実装されていない場合にはDConnectServiceInformationProfileConnectStateNoneをレスポンスとして返却する。
 
 @param[in] profile プロファイル
 @param[in] serviceId サービスID
 
 @retval DConnectServiceInformationProfileConnectStateNone 非対応
 @retval DConnectServiceInformationProfileConnectStateOn 接続ON
 @retval DConnectServiceInformationProfileConnectStateOff 接続OFF
 */
- (DConnectServiceInformationProfileConnectState) profile:(DConnectServiceInformationProfile *)profile
                        wifiStateForServiceId:(NSString *)serviceId;

/*!
 @brief データソースにBluetoothの接続状態を要求する。
 
 実装されていない場合にはDConnectServiceInformationProfileConnectStateNoneをレスポンスとして返却する。
 
 @param[in] profile プロファイル
 @param[in] serviceId サービスID
 
 @retval DConnectServiceInformationProfileConnectStateNone 非対応
 @retval DConnectServiceInformationProfileConnectStateOn 接続ON
 @retval DConnectServiceInformationProfileConnectStateOff 接続OFF
 */
- (DConnectServiceInformationProfileConnectState) profile:(DConnectServiceInformationProfile *)profile
                   bluetoothStateForServiceId:(NSString *)serviceId;

/*!
 @brief データソースにNFCの接続状態を要求する。
 
 実装されていない場合にはDConnectServiceInformationProfileConnectStateNoneをレスポンスとして返却する。
 
 @param[in] profile プロファイル
 @param[in] serviceId サービスID
 
 @retval DConnectServiceInformationProfileConnectStateNone 非対応
 @retval DConnectServiceInformationProfileConnectStateOn 接続ON
 @retval DConnectServiceInformationProfileConnectStateOff 接続OFF
 */
- (DConnectServiceInformationProfileConnectState) profile:(DConnectServiceInformationProfile *)profile
                         nfcStateForServiceId:(NSString *)serviceId;

/*!
 @brief データソースにBLEの接続状態を要求する。
 
 実装されていない場合にはDConnectServiceInformationProfileConnectStateNoneをレスポンスとして返却する。
 
 @param[in] profile プロファイル
 @param[in] serviceId サービスID
 
 @retval DConnectServiceInformationProfileConnectStateNone 非対応
 @retval DConnectServiceInformationProfileConnectStateOn 接続ON
 @retval DConnectServiceInformationProfileConnectStateOff 接続OFF
 */
- (DConnectServiceInformationProfileConnectState) profile:(DConnectServiceInformationProfile *)profile
                         bleStateForServiceId:(NSString *)serviceId;

@end

/*!
 @class DConnectServiceInformationProfile
 @brief Systemプロファイル。
 
 System Profileの各APIへのリクエストを受信する。
 受信したリクエストは各API毎にデリゲートに通知される。
 */
@interface DConnectServiceInformationProfile : DConnectProfile

/*!
 @brief DConnectServiceInformationProfileのデリゲートオブジェクト。
 
 デリゲートは @link DConnectServiceInformationProfileDelegate @endlink を実装しなくてはならない。
 デリゲートはretainされない。
 */
@property (nonatomic, weak) id<DConnectServiceInformationProfileDelegate> delegate;

/*!
 @brief DConnectServiceInformationProfileのデータソースオブジェクト。
 
 データソースは @link DConnectServiceInformationProfileDataSource @endlink を実装しなくてはならない。
 データソースはretainされない。
 */
@property (nonatomic, weak) id<DConnectServiceInformationProfileDataSource> dataSource;

#pragma mark - Setter

/*!
 @brief メッセージにサポートしているI/Fの一覧を格納する。
 
 @param[in] supports サポートしているI/F一覧
 @param[in,out] message I/Fの一覧を格納するメッセージ
 */
+ (void) setSupports:(DConnectArray *)supports target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスの接続状態を設定する。
 
 @param[in] connect デバイスの接続状態
 @param[in,out] message デバイスの接続状態を格納するメッセージ
 */
+ (void) setConnect:(DConnectMessage *)connect target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグインのWiFiの接続状態を設定する。
 
 @param[in] state 接続状態
 @param[in,out] message WiFiの接続状態を格納するメッセージ
 */
+ (void) setWiFiState:(DConnectServiceInformationProfileConnectState)state target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグインのBluetoothの接続状態を設定する。
 
 @param[in] state 接続状態
 @param[in,out] message Bluetoothの接続状態を格納するメッセージ
 */
+ (void) setBluetoothState:(DConnectServiceInformationProfileConnectState)state target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグインのNFCの接続状態を設定する。
 
 @param[in] state 接続状態
 @param[in,out] message NFCの接続状態を格納するメッセージ
 */
+ (void) setNFCState:(DConnectServiceInformationProfileConnectState)state target:(DConnectMessage *)message;

/*!
 @brief メッセージにデバイスプラグインのBLEの接続状態を設定する。
 
 @param[in] state 接続状態
 @param[in,out] message BLEの接続状態を格納するメッセージ
 */
+ (void) setBLEState:(DConnectServiceInformationProfileConnectState)state target:(DConnectMessage *)message;

@end
