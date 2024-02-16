#ifndef FIRST_CHALLENGE_HPP
#define FIRST_CHALLENGE_HPP

// 以下に示すライブラリ，ヘッダファイルをインクルード
// rclcpp/rclcpp.hpp
// functional
// memory
// optional
// nav_msgs/msg/odometry.hpp
// roomba_500driver_meiji/msg/roomba_ctrl.hpp
// ここに書く

class FirstChallenge : public rclcpp::Node
{
    public:
        FirstChallenge();
        void process();

        // コールバック関数
        // nav_msgs::msg::Odometry型のmsgをコールバック
        void odometry_callback(/*引数を指定*/);

        // 関数
        bool can_move();                        // センサ情報（今回はodom）を取得できているかの確認用
        bool is_goal();                         // 終了判定
        double calc_distance();                 // 進んだ距離を計算
        void run(float velocity, float omega);  // roombaの制御入力を決定
        void set_cmd_vel();                     // 並進速度と旋回速度を計算

        // 変数
        int hz_ = 10;
        double goal_dist_ = 0.0;
        double velocity_ = 0.0;
        // odom_をoptional型で定義
        /*ここに追記*/<nav_msgs::msg::Odometry> odom_;  // optional型で定義することによりodomをsubできたかの判定も同時に行う
        roomba_500driver_meiji::msg::RoombaCtrl cmd_vel_;

        // Pub & Sub
        // subscriberはnav_msgs::msg::Odometry型のトピックをsubscribe
        // publisherはroomba_500driver_meiji::msg::RoombaCtrl型のトピックをpublish
        /*ここに追記*/ odom_sub_;                  // odom
        /*ここに追記*/ cmd_vel_pub_;  // 制御入力
};


#endif  // FIRST_CHALLENGE_HPP