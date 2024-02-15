#include "first_challenge/first_challenge.hpp"

FirstChallenge::FirstChallenge() : Node("first_challenge")
{
    // subscriber
    // <subscriber名> = this->create_subscription<<msg型>>("<topic名>", rclcpp::QoS(<確保するtopicサイズ>).reliable(), std::bind(&<class名>::<コールバック関数名>, this, std::placeholders::_<何番目の引数か>));
    // std::bindを使ってsubするコールバック関数，std::placeholdersを使ってその関数内での引数を指定する
    // std::placeholdersで指定する引数は大体1番目のもの（コールバック関数の引数が1つであるため）
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>("/roomba/odometry", rclcpp::QoS(1).reliable(), std::bind(&FirstChallenge::odometry_callback, this, std::placeholders::_1));

    // publisher
    // <publisher名> = this->create_publisher<<msg型>>("<topic名>", rclcpp::QoS(<確保するtopicサイズ>).reliable());
    cmd_vel_pub_ = this->create_publisher<roomba_500driver_meiji::RoombaCtrl>("/roomba/cmd_vel", rclcpp::QoS(1).reliable());
}

// odomのコールバック関数
void FirstChallenge::odometry_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    odom_ = *msg;
}

// センサ情報（今回はodom）を取得できているかの確認用
// センサ情報取得前にアクセスしようとするとセグメンテーションフォルトが起こり，core dump（プロセス終了）する
bool FirstChallenge::can_move()
{
    // odom_はoptional型で定義しているため，has_value()が使える
    // optional型のhas_value()では，値を取得できた場合はtrue，取得できなかった場合はfalseを返す
    return odom_.has_value();
}

// 終了判定
// roombaが一定以上の距離を進んだら終了
bool FirstChallenge::is_finish()
{
    const double dist = calc_distance();

    if(distance > goal_dist)
        return true;
    else
        return false;
}

// 進んだ距離を計算
double FirstChallenge::calc_distance()
{
    return hypot(odom_.pose.position.x, odom_.pose.position.y);
}



