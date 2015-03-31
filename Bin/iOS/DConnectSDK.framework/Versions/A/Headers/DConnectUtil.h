//
//  DConnectUtil.h
//  DConnectSDK
//
//  Copyright (c) 2014 NTT DOCOMO,INC.
//  Released under the MIT license
//  http://opensource.org/licenses/mit-license.php
//

/*! 
 @file
 @brief Device Connect のAPIを利用するためのユーティリティ機能を提供する。
 @author NTT DOCOMO
 */
#import <DConnectSDK/DConnectMessage.h>

/*!
 @brief 認証成功通知コールバック。
 
 @param[in] clientId クライアントID
 @param[in] accessToken アクセストークン
 */
typedef void (^DConnectAuthorizationSuccessBlock)(NSString *clientId, NSString *accessToken);

/*!
 @brief 認証失敗通知コールバック。
 
 @param[in] errorCode エラーコード
 */
typedef void (^DConnectAuthorizationFailBlock)(DConnectMessageErrorCodeType errorCode);

/*!
 @class DConnectUtil
 @brief Device Connect のAPIを利用するためのユーティリティ機能を提供するクラス。
 */
@interface DConnectUtil : NSObject

/*!
 @brief 非同期的に認証処理を行う。
 
 <p>
 originにはアプリのオリジンを格納する。iOSではBundle Identifierを格納する。<br/>
 appNameは認証確認ダイアログに表示されるアプリ名を指定する。<br/>
 scopesには、アプリで使用するプロファイルの一覧を指定する。ここに指定の無いプロファイルは使用することができない。<br/>
 </p>
 
 <p>
 既にクライアントが作成されている場合に再度同じoriginで作成しようとした場合には、新規でクライアントを作成する。
 以前のクライアントは使用できなくなるので、注意が必要。
 </p>
 @param[in] origin オリジン
 @param[in] appName アプリ名
 @param[in] scopes 使用するプロファイル一覧
 @param[in] success 認証成功通知コールバック
 @param[in] error 認証失敗通知コールバック
 */
+ (void) asyncAuthorizeWithOrigin:(NSString *)origin
                          appName:(NSString *)appName
                           scopes:(NSArray *)scopes
                          success:(DConnectAuthorizationSuccessBlock)success
                            error:(DConnectAuthorizationFailBlock)error;

/*!
 @brief 同期的に認証処理を行う。
 
 <p>
 originにはアプリのオリジンを格納する。iOSではBundle Identifierを格納する。<br/>
 appNameは認証確認ダイアログに表示されるアプリ名を指定する。<br/>
 scopesには、アプリで使用するプロファイルの一覧を指定する。ここに指定の無いプロファイルは使用することができない。<br/>
 </p>
 <p>
 既にクライアントが作成されている場合に再度同じoriginで作成しようとした場合には、新規でクライアントを作成する。
 以前のクライアントは使用できなくなるので、注意が必要。
 </p>
 @param[in] origin オリジン
 @param[in] appName アプリ名
 @param[in] scopes 使用するプロファイル一覧
 @param[in] success 認証成功通知コールバック
 @param[in] error 認証失敗通知コールバック
 */
+ (void) authorizeWithOrigin:(NSString *)origin
                     appName:(NSString *)appName
                      scopes:(NSArray *)scopes
                     success:(DConnectAuthorizationSuccessBlock)success
                       error:(DConnectAuthorizationFailBlock)error;

/*!
 @brief 同期的にアクセストークンをリフレッシュする。
 
 @param[in] clientId クライアントID
 @param[in] appName アプリ名
 @param[in] scopes 使用するプロファイル一覧
 @param[in] success 認証成功通知コールバック
 @param[in] error 認証失敗通知コールバック
 */
+ (void) refreshAccessTokenWithClientId:(NSString *)clientId
                                appName:(NSString *)appName
                                 scopes:(NSArray *)scopes
                                success:(DConnectAuthorizationSuccessBlock)success
                                  error:(DConnectAuthorizationFailBlock)error;

/*!
 @brief 指定されたNSArrayを連結した文字列に変換する。
 
 @param[in] scopes スコープ一覧が格納された配列
 
 @retval 連結された文字列
 @retval nil 連結に失敗した場合
 */
+ (NSString *) combineScopes:(NSArray *)scopes;

/*!
 @brief DConnectManagerが管理するアクセストークンの一覧を表示する。
 
 現在のトップのViewControllerに対し、モーダルビューでアクセストークンの一覧画面を表示する。
 */
+ (void) showAccessTokenList;


+ (void) showOriginWhitelist;

@end
