//
//  DConnectCanvasProfile.h
//  DConnectSDK
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*!
 @file
 @brief Canvasプロファイルを実装するための機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectProfile.h>

/*!
 @brief プロファイル名。
 */
extern NSString *const DConnectCanvasProfileName;

/*!
 @brief パラメータ: mimetype。
 */
extern NSString *const DConnectCanvasProfileParamMIMEType;

/*!
 @brief パラメータ: data。
 */
extern NSString *const DConnectCanvasProfileParamData;

/*!
 @brief パラメータ: X。
 */
extern NSString *const DConnectCanvasProfileParamX;

/*!
 @brief パラメータ: Y。
 */
extern NSString *const DConnectCanvasProfileParamY;

/*!
 @brief パラメータ: mode。
 */
extern NSString *const DConnectCanvasProfileParamMode;


/*!
 @brief 画像描画モード: アスペクト比を保持して画面いっぱいに表示する。
 */
extern NSString *const DConnectCanvasProfileModeScales;

/*!
 @brief 画像描画モード: 画像を並べて敷き詰める。
 */
extern NSString *const DConnectCanvasProfileModeFills;




@class DConnectCanvasProfile;

/*!
 @protocol DConnectCanvasProfileDelegate
 @brief Canvas Profile各のAPIリクエスト通知用デリゲート。
 
 Canvas Profileの各APIへのリクエスト受信通知を受け取るデリゲート。
 */
@protocol DConnectCanvasProfileDelegate <NSObject>
@optional

#pragma mark - Post Methods

/*!
 @brief 画像描画リクエストを受け取ったことをデリゲートに通知する。
 
 profileが画像リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Canvas DrawImage API [POST]
 </p>
 
 @param[in] profile このイベントを通知するDConnectCanvasProfileのオブジェクト
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @param[in] mimeType マイムタイプ。省略された場合はnil。
 @param[in] data ファイルのバイナリデータ
 @param[in] x X座標
 @param[in] y Y座標
 @param[in] mode 画像描画モード
 @retval YES レスポンスパラメータを返却する
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlink で返却すること。
 */
- (BOOL) profile:(DConnectCanvasProfile *)profile didReceivePostDrawImageRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
        serviceId:(NSString *)serviceId
        mimeType:(NSString *)mimeType
            data:(NSData *)data
               imageX:(double)imageX
               imageY:(double)imageY
            mode:(NSString *)mode;


#pragma mark - Delete Methods

/*!
 @brief 画像描画削除リクエストを受け取ったことをデリゲートに通知する。
 
 profileが画像描画削除リクエストを受け取ったことをデリゲートに通知する。<br>
 実装されない場合には、Not supportのエラーが返却される。
 
 <p>
 [対応するAPI] Canvas DrawImage API [DELETE]
 </p>
 
 @param[in] profile このイベントを通知するDConnectCanvasProfileのオブジェクト
 @param[in] request リクエスト
 @param[in,out] response レスポンス
 @param[in] serviceId サービスID
 @retval YES レスポンスパラメータを返却する
 @retval NO レスポンスパラメータを返却しないので、@link DConnectManager::sendResponse: @endlink で返却すること。
 */
- (BOOL) profile:(DConnectCanvasProfile *)profile didReceiveDeleteDrawImageRequest:(DConnectRequestMessage *)request
        response:(DConnectResponseMessage *)response
       serviceId:(NSString *)serviceId;

@end


/*!
 @class DConnectCanvasProfile
 @brief Canvasプロファイル。
 
 Canvas Profileの各APIへのリクエストを受信する。
 受信したリクエストは各API毎にデリゲートに通知される。
 */
@interface DConnectCanvasProfile : DConnectProfile

/*!
 @brief DConnectCanvasProfileのデリゲートオブジェクト。
 
 デリゲートは @link DConnectCanvasProfileDelegate @endlink を実装しなくてはならない。
 デリゲートはretainされない。
 */
@property (nonatomic, weak) id<DConnectCanvasProfileDelegate> delegate;

#pragma mark - Setter

/*!
 @brief メッセージにマイムタイプを設定する。
 @param[in] mimeType マイムタイプ
 @param[in,out] message マイムタイプを格納するメッセージ
 */
+ (void) setMIMEType:(NSString *)mimeType target:(DConnectMessage *)message;

/*!
 @brief メッセージに画像ファイルのバイナリを設定する。
 @param[in] data 画像ファイルのバイナリ
 @param[in,out] message 画像ファイルのバイナリを格納するメッセージ
 */
+ (void) setData:(NSData *)data target:(DConnectMessage *)message;

/*!
 @brief メッセージにX座標を設定する。
 @param[in] x X座標
 @param[in,out] message X座標を格納するメッセージ
 */
+ (void) setX:(double)x target:(DConnectMessage *)message;

/*!
 @brief メッセージにY座標を設定する。
 @param[in] y Y座標
 @param[in,out] message Y座標を格納するメッセージ
 */
+ (void) setY:(double)y target:(DConnectMessage *)message;

/*!
 @brief メッセージに画像描画モードを設定する。
 @param[in] mode 画像描画モード
 @param[in,out] message 画像描画モードを格納するメッセージ
 */
+ (void) setMode:(NSString *)mode target:(DConnectMessage *)message;


#pragma mark - Getter

/*!
 @brief リクエストデータからマイムタイプを取得する。
 @param[in] request リクエストパラメータ
 @return マイムタイプ。無い場合はnilを返す。
 */
+ (NSString *) mimeTypeFromRequest:(DConnectMessage *)request;

/*!
 @brief リクエストデータから画像ファイルのバイナリを取得する。
 @param[in] request リクエストパラメータ
 @return 画像ファイルのバイナリ。無い場合はnilを返す。
 */
+ (NSData *) dataFromRequest:(DConnectMessage *)request;

/*!
 @brief リクエストデータからX座標を取得する。
 @param[in] request リクエストパラメータ
 @return X座標。無い場合はnilを返す。
 */
+ (NSString *) xFromRequest:(DConnectMessage *)request;

/*!
 @brief リクエストデータからY座標を取得する。
 @param[in] request リクエストパラメータ
 @return Y座標。無い場合はnilを返す。
 */
+ (NSString *) yFromRequest:(DConnectMessage *)request;

/*!
 @brief リクエストデータから画像描画モードを取得する。
 @param[in] request リクエストパラメータ
 @return 画像描画モード。無い場合はnilを返す。
 */
+ (NSString *) modeFromRequest:(DConnectMessage *)request;

@end
