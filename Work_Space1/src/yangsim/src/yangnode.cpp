#include "rclcpp/rclcpp.hpp"
#include  "interfaces/msg/first_msg_message.hpp"                       

#include  "interfaces/srv/first_srevice_message.hpp"
#include<iostream>                          

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>

using namespace std;
using namespace std::chrono_literals;
using std::placeholders::_1 ;
using std::placeholders::_2 ;

class yang : public rclcpp::Node
{
public : string colour[7] = { "Hi Yin, I am Yang the opposite of you.",
"Yes, Yin; we ourselves, do not mean anything since we are only employed to express a relation",
"Precisely, Yin; we are used to describe how things function inrelation to each other and to the universe.",
"For what is and what is not beget each other.",
"High and low place each other.",
"Before and behind follow each other.",
"And you fade into the darkness." } ;
public : bool isClient = false;
public : int64_t stage = 0     ;
public:
    yang() : Node("conversation_yang_yin")
    {
            server_ = this->create_service<interfaces::srv::FirstSreviceMessage>(
                "yang_srv",
                std::bind(&yang::callbackService, this, _1, _2));
            publisher_ = this->create_publisher<interfaces::msg::FirstMsgMessage>("conversation", 10);


            RCLCPP_INFO(this->get_logger(), "Server has been started");
            timer = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&yang::YangAsClient, this));
            
            
    }
   void callbackService(const interfaces::srv::FirstSreviceMessage::Request::SharedPtr request  , 
                         const interfaces::srv::FirstSreviceMessage::Response::SharedPtr response  ){
                      
                        std::string str = request->message;
                        int64_t len = request->len;
                        auto message1 = interfaces::msg::FirstMsgMessage();
                        int64_t sum = this->asci_convertor(str , len) ;

                        message1.message = "yin said : Message ->  " +str+ "length -> "+ std::to_string(len)+"result ->"+std::to_string(sum);
                        publisher_->publish(message1);

                        response->result = sum  ;
                        this->isClient = true ;
                        
                         }
    int asci_convertor(std::string message , int64_t length){
          message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
          int64_t sum=0;
            for (int i =0 ; i < length ; i++){
                sum+=(int)message[i];
            }
            return sum;
    }
    void YangAsClient(){
            if (this->isClient){ 
            threads_.push_back(std::thread(std::bind(&yang::callForMessage,this, this->colour[this->stage])));
            this->stage += 1 ;
            this->isClient = false ;
            }
    }
    void callForMessage(std::string message)
    {
        auto client = this->create_client<interfaces::srv::FirstSreviceMessage>("yin_service");
        auto request = std::make_shared<interfaces::srv::FirstSreviceMessage::Request>() ; 
        int64_t number_of_character = message.length() ;
        request->message = message ;
        request->len =  number_of_character;
        while (!client->wait_for_service(std::chrono::seconds(1)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the server to be up...");
        }
        auto future  = client->async_send_request(request) ;

      
        try
        {
            auto response = future.get();
               
            cout<<this->colour[this->stage];
            RCLCPP_INFO(this->get_logger(), "  get the response  %ld " , response->result);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }
    }

private:
    std::vector<std::thread> threads_;
    rclcpp::Service<interfaces::srv::FirstSreviceMessage>::SharedPtr server_ ;
    rclcpp::TimerBase::SharedPtr timer ;
    rclcpp::Publisher<interfaces::msg::FirstMsgMessage>::SharedPtr publisher_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<yang>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}