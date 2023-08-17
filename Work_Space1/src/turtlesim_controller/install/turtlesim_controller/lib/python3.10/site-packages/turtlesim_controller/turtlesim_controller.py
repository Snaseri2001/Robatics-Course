
import rclpy
import rclpy.node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose


class MinimalParam(rclpy.node.Node):
    state = 0   
    def __init__(self):
        super().__init__('turtlesim_controller')
        self.declare_parameter('stop', 'false')
        self.subscribe = self.create_subscription(Pose,'turtle1/pose' ,self.listener, 10)
        
        self.subscribe
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

    


        if my_param == 'false' :
            self
        else :
            pass 





def main(args = None):
        rclpy.init(args=args)
        node = MinimalParam()
        rclpy.spin(node)

if __name__ == '__main__':
    main()