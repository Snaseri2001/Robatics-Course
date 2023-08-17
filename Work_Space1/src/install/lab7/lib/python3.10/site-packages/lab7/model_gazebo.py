import rclpy
from rclpy.node import Node
import time
import random 
from rclpy.action import ActionClient
from geometry_msgs.msg import Twist


class modelgazebo(Node):
    def __init__(self):

        self.velocity = 1.0

        super().__init__('our robot in gszebo')
        
        
        self.publish = self.create_publisher(Twist, '/cmd_vel', 10)
        self.call_timer = self.create_timer(2.0, self._timer_cb)


    def _timer_cb(self):
        
        velocity = Twist()
        velocity.angular.z = 0.0
        velocity.linear.x = 1.0
        self.velocity = self.velocity * -1
                
        self.publish.publish(velocity)
    
def main(args=None):    
    rclpy.init(args=args)
    model = modelgazebo()
    rclpy.spin(model)
    rclpy.shutdown()


if __name__ == '__main__':
    main()