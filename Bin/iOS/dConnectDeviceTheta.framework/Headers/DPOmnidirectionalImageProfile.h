//
//  DPOmnidirectionalImageProfile.h
//  dConnectDeviceTheta
//
//  Copyright (c) 2015 NTT DOCOMO, INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//


/*! @file
 @brief OmnidirectionalImageプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 @date 作成日(2015.8.23)
 */
#import <DConnectSDK/DConnectSDK.h>

/*! @brief プロファイル名: omnidirectional_image。 */
extern NSString *const DPOmnidirectionalImageProfileName;


/*! @brief インタフェース名: roi。*/
extern NSString *const DPOmnidirectionalImageProfileInterfaceROI;

/*! @brief 属性: roi。 */
extern NSString *const DPOmnidirectionalImageProfileAttrROI;

/*! @brief 属性: settings。*/
extern NSString *const DPOmnidirectionalImageProfileAttrSettings;

/*! @brief パラメータ: source。 */
extern NSString *const DPOmnidirectionalImageProfileParamSource;

/*! @brief パラメータ: x。 */
extern NSString *const DPOmnidirectionalImageProfileParamX;

/*! @brief パラメータ: y。*/
extern NSString *const DPOmnidirectionalImageProfileParamY;

/*! @brief パラメータ: z。*/
extern NSString *const DPOmnidirectionalImageProfileParamZ;

/*! @brief パラメータ: roll。*/
extern NSString *const DPOmnidirectionalImageProfileParamRoll;

/*! @brief パラメータ: pitch。*/
extern NSString *const DPOmnidirectionalImageProfileParamPitch;

/*! @brief パラメータ: yaw。 */
extern NSString *const DPOmnidirectionalImageProfileParamYaw;

/*! @brief パラメータ: fov。*/
extern NSString *const DPOmnidirectionalImageProfileParamFOV;

/*! @brief パラメータ: sphereSize。*/
extern NSString *const DPOmnidirectionalImageProfileParamSphereSize;

/*! @brief パラメータ: width。*/
extern NSString *const DPOmnidirectionalImageProfileParamWidth;

/*! @brief パラメータ: height。*/
extern NSString *const DPOmnidirectionalImageProfileParamHeight;

/*! @brief パラメータ: stereo。*/
extern NSString *const DPOmnidirectionalImageProfileParamStereo;

/*! @brief パラメータ: vr。*/
extern NSString *const DPOmnidirectionalImageProfileParamVR;

/*! @brief パラメータ: uri。*/
extern NSString *const DPOmnidirectionalImageProfileParamURI;



@class DPOmnidirectionalImageProfile;
/*!
 @brief OmnidirectionalImage プロファイル。
 <p>
 全天球画像のスクリーンショットを提供するAPI。<br/>
 全天球画像取得機能を提供するデバイスプラグインは当クラスを継承し、対応APIを実装すること。 <br/>
 </p>
 */
@protocol DPOmnidirectionalImageProfileDelegate<NSObject>
@optional


/*!
 @brief 全天球画像を取得する.<br>
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 GET http://{dConnectドメイン}/omnidirectional_image/roi?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] source 全天球画像のURI
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                     profile:(DPOmnidirectionalImageProfile *)profile
    didReceiveGetRoiRequest:(DConnectRequestMessage *)request
                            response:(DConnectResponseMessage *)response
                           serviceId:(NSString *)serviceId
                              source:(NSString *)source;



/*!
 @brief 全天球画像を取得を開始する.<br>
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 PUT http://{dConnectドメイン}/omnidirectional_image/roi?serviceId=xxxxx&source=yyyyyyyyy
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] source 全天球画像のURI
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                     profile:(DPOmnidirectionalImageProfile *)profile
             didReceivePutRoiRequest:(DConnectRequestMessage *)request
                            response:(DConnectResponseMessage *)response
                           serviceId:(NSString *)serviceId
                              source:(NSString *)source;

/*!
 @brief 取得する全天球画像を設定する.<br>
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 PUT http://{dConnectドメイン}/omnidirectional_image/roi/settings?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                     profile:(DPOmnidirectionalImageProfile *)profile
             didReceivePutRoiSettingsRequest:(DConnectRequestMessage *)request
                            response:(DConnectResponseMessage *)response
                           serviceId:(NSString *)serviceId;


/*!
 @brief 全天球画像の取得を中止する.<br>
 実装されない場合には、Not supportのエラーが返却される。
 <pre>
 [対応するRESTful]
 DELETE http://{dConnectドメイン}/omnidirectional_image/roi?serviceId=xxxxx
 </pre>
 @param[in] profile プロファイル
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] uri URI
 @retval YES レスポンスパラメータを返却する。
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlinkで返却すること。
 */
- (BOOL)                     profile:(DPOmnidirectionalImageProfile *)profile
     didReceiveDeleteRoiRequest:(DConnectRequestMessage *)request
                            response:(DConnectResponseMessage *)response
                           serviceId:(NSString *)serviceId
                                 uri:(NSString *)uri;

@end

@interface DPOmnidirectionalImageProfile : DConnectProfile
/*!
 @brief DPOmnidirectionalImageProfileのデリゲートオブジェクト。
 
 デリゲートは @link DPOmnidirectionalImageProfileDelegate @endlink を実装しなくてはならない。
 デリゲートはretainされない。
 */
@property (nonatomic, assign) id<DPOmnidirectionalImageProfileDelegate> delegate;

@end
