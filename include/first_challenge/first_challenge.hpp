#ifndef FIRST_CHALLENGE_HPP
#define FIRST_CHALLENGE_HPP

#include <rclcpp/rclcpp.hpp>
#include <functional>  // bind & placeholders用
#include <memory>      // SharedPtr用
#include <optional>    // has_value()用

#include <nav_msgs/msg/odometry.hpp>
#include <roomba_500driver_meiji/roombaCtrl.hpp>

class FirstChallenge : public rclcpp::Node
{
    public:
        FirstChallenge();
        void process();

    private:
        // コールバック関数
        void odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

        // 関数
        bool can_move();                          // センサ情報（今回はodom）を取得できているかの確認用
        bool is_finish();                         // 終了判定
        double calc_distance();                   // 進んだ距離を計算
        void run(float velocity, float omega);

        int hz_ = 10;
        double goal_dist_ = 0.0;
        // float len_;
        // float rot_;
        // float rotcount_;
        // float lenscan_;
        std::optional<nav_msgs::msg::Odometry> odom_;  // optional型で定義することによりodomをsubできたかの判定も同時に行う

        // Pub & Sub
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;             // odom
        rclcpp::Publisher<roomba_500driver_meiji::RoombaCtrl>::SharedPtr cmd_vel_pub_;  // 制御入力
};


#endif  // FIRST_CHALLENGE_HPP