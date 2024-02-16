// first_challenge.hppをインクルード
// ここに書く

FirstChallenge::FirstChallenge() : Node("first_challenge")
{
    // global変数を定義
    hz_ = this->declare_parameter<int>("hz", 10);  // hz_のデフォルト値を10に設定
    // hz_の場合を参考にgoal_dist_とvelocity_について書く
    // デフォルト値は以下のようにする
    // goal_dist_ : 1.0
    // velocity_  : 0.1
    // ここに書く

    // subscriber
    // <subscriber名> = this->create_subscription<<msg型>>("<topic名>", rclcpp::QoS(<確保するtopicサイズ>).reliable(), std::bind(&<class名>::<コールバック関数名>, this, std::placeholders::_<何番目の引数か>));
    // std::bindを使ってsubするコールバック関数，std::placeholdersを使ってその関数内での引数を指定する
    // std::placeholdersで指定する引数は大体1番目のもの（コールバック関数の引数が1つであるため）
    odom_sub_ = /*ここに追記*/

    // publisher
    // <publisher名> = this->create_publisher<<msg型>>("<topic名>", rclcpp::QoS(<確保するtopicサイズ>).reliable());
    cmd_vel_pub_ = /*ここに追記*/
}

// odomのコールバック関数
void FirstChallenge::odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    // msgを取得
    odom_ = *msg;
}

// センサ情報（今回はodom）を取得できているかの確認用
// センサ情報取得前にアクセスしようとするとセグメンテーションフォルトが起こり，core dump（プロセス終了）する
bool FirstChallenge::can_move()
{
    // optional型のhas_value()を使用し，odom_を取得できたかの判定をすること
    // 値を取得できた場合はtrue，取得できなかった場合はfalseを返すこと
    // ここに書く
}

// 終了判定
// roombaが一定以上の距離を進んだら終了
// ゴールするまでtrueを返す
bool FirstChallenge::is_goal()
{
    // calc_distance()を使用すること
    // ここに書く
}

// 進んだ距離を計算
double FirstChallenge::calc_distance()
{
    // 距離を計算する際はhypot関数を使うこと
    // optional型のvalue()を使用し，odom_の値を取得すること
    // ここに書く
}

// roombaの制御入力を決定
void FirstChallenge::run(float velocity, float omega)
{
    // roombaの制御モード
    // 基本的に11（DRIVE_DIRECT）固定で良い
    cmd_vel_.mode = 11;

    // 並進速度を指定
    // ここに書く
    // 旋回速度を指定
    cmd_vel_.cntl.angular.z = omega;

    // cmd_velをpublish
    // <publisher名>->publish(<変数名>);
    // ここに書く
}

// 並進速度と旋回速度を計算
void FirstChallenge::set_cmd_vel()
{
    // 計算した制御入力はrun()に渡すこと
    // ここに書く
}