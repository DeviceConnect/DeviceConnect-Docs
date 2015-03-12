//
//  DCMDriveControllerProfileName.h
//  DCMDevicePluginSDK
//
//  Copyright (c) 2014 NTT DOCOMO, INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//
/*! @file
 @brief DriveControllerプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 @date 作成日(2014.7.22)
 */
#import <DConnectSDK/DConnectSDK.h>
/*! @brief プロファイル名: drive_controller。 */
extern NSString *const DCMDriveControllerProfileName;
/*!
 @brief 属性: move。
 */
extern NSString *const DCMDriveControllerProfileAttrMove;
/*!
 @brief 属性: stop。
 */
extern NSString *const DCMDriveControllerProfileAttrStop;
/*!
 @brief 属性: rotate。
 */
extern NSString *const DCMDriveControllerProfileAttrRotate;
/*!
 @brief パラメータ: angle。
 */
extern NSString *const DCMDriveControllerProfileParamAngle;
/*!
 @brief パラメータ: speed。
 */
extern NSString *const DCMDriveControllerProfileParamSpeed;

@class DCMDriveControllerProfile;

/*!
 @brief DriveController プロファイル。
 
 <p>
 デバイスの操作機能を提供するAPI。<br/>
 デバイスの操作機能を提供するデバイスプラグインは当クラスを継承し、対応APIを実装すること。 <br/>
 </p>
 */
@protocol DCMDriveControllerProfileDelegate<NSObject>
@optional

/*!
 @brief デバイスを操作できる<br>
 
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 POST http://{dConnectドメイン}/drive_controller/move?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] angle 方向
 @param[in] speed 速度
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                            profile:(DCMDriveControllerProfile *)profile
   didReceivePostDriveControllerMoveRequest:(DConnectRequestMessage *)request
                                   response:(DConnectResponseMessage *)response
                                   serviceId:(NSString *)serviceId
                                      angle:(double)angle
                                      speed:(double)speed ;
/*!
 @brief デバイスを回転できる<br>
 
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 PUT http://{dConnectドメイン}/drive_controller/rotate?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] angle 回転方向
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                              profile:(DCMDriveControllerProfile *)profile
    didReceivePutDriveControllerRotateRequest:(DConnectRequestMessage *)request
                                     response:(DConnectResponseMessage *)response
                                     serviceId:(NSString *)serviceId
                                        angle:(double)angle;
/*!
 @brief デバイスを停止させる<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <pre>
 [対応するRESTful]
 DELETE http://{dConnectドメイン}/drive_controller/stop?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
@param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                               profile:(DCMDriveControllerProfile *)profile
    didReceiveDeleteDriveControllerStopRequest:(DConnectRequestMessage *)request
                                      response:(DConnectResponseMessage *)response
                                      serviceId:(NSString *)serviceId ;
@end

/*!
 @class DCMDriveControllerProfile
 @brief DriveControllerプロファイル。
 
 DriveController Profileの各APIへのリクエストを受信する。
 受信したリクエストは各API毎にデリゲートに通知される。
 */
@interface DCMDriveControllerProfile : DConnectProfile
/*!
 @brief DCMDriveControllerProfileのデリゲートオブジェクト。
 
 デリゲートは @link DCMDriveControllerProfileDelegate @endlink を実装しなくてはならない。
 デリゲートはretainされない。
 */
@property (nonatomic, assign) id<DCMDriveControllerProfileDelegate> delegate;

@end
