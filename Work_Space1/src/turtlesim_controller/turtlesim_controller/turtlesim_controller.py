
import rclpy
import rclpy.node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from rclpy.action import ActionClient 
from turtlesim.action import RotateAbsolute

class MinimalParam(rclpy.node.Node):
    state = 0   
    def __init__(self):
        super().__init__('turtlesim_controller')
        self.declare_parameter('stop', 'false')
        self.subscribe = self.create_subscription(Pose,'turtle1/pose' ,self.listener, 10)
        
        self.subscribe
        self.goalSend = True
        self._action_server = ActionClient(
            self
            ,RotateAbsolute
            ,'turtle1/rotate_absoloute'
            ,self.execute_callback)
        self.publisher = self.create_publisher(Twist , "/turtle1/cmd_vel" , 10 )
        time_priod = 0.5
        self.timer = self.create_timer(time_priod , self.timer_callback)
        # msg = Pose()
        # msg.x = 0
        # msg.y = 0
        # msg.theta = 0
       
    def listener (self , msg1) :
         if msg1.x <= 0 or msg1.y <= 0 or msg1.x > 11 or msg1.y > 11:
              self.state = 1 
        
    def callbakc1(self, predict):
        goal_handle = predict.result()
       
        if not goal_handle.accepted:
            return
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedbackCallback(self, msg):
        feedback = msg.feedback
        self.get_logger().info(feedback.remaining)

    def result(self, predict):
       
        result = predict.result().result
        self.state=3 


    def timer_callback(self ) :
        
        my_param = self.get_parameter('stop').get_parameter_value().string_value
        twist = Twist()
        if my_param == 'false'  : 
            print("hello")

            if self.state == 0 :
                #  we are in backward state it must move backward for 2 second
               
                
                    twist.linear.x = 1.0
                    twist.linear.y = 0.0
                    twist.linear.z = 0.0
        
                    twist.angular.x = 0.0 
                    twist.angular.y = 0.0
                    twist.angular.z = 0.0 


                

            
            elif self.state == 1 :
                    twist.linear.x = -4.0
                    twist.linear.y = 0.0
                    twist.linear.z = 0.0
            
                    twist.angular.x = 0.0
                    twist.angular.y = 0.0
                    twist.angular.z = 0.0
                    self.state = 3

               
            elif  self.state == 2 : 

                twist.linear.x = 0.0
                twist.linear.y = 0.0
                twist.linear.z = 0.0
            
                twist.angular.x = 0.0
                twist.angular.y = 0.0
                twist.angular.z = 0.0
            

            self.publisher.publish(twist)

    


        elif self.state == 3 :
             


              if self.goalSend == False:
                action  = RotateAbsolute.Goal()
                
                self._action_client.wait_for_server()
                self._send_goal_future = self._action_client.send_goal_async( action, feedback_callback=self.feedback_callback)
                self._send_goal_future.add_done_callback(self.goal_response_callback)
                self.goalSend = True

              else :
                velocity = Twist()
                velocity.linear.x = 0.0
                self.publisher_.publish(velocity)






def main(args = None):
        rclpy.init(args=args)
        node = MinimalParam()
        rclpy.spin(node)

if __name__ == '__main__':
    main()