import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Image
from std_msgs.msg import String
import matplotlib.pyplot as plt
import numpy as np 

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        print("Statrt")
        self.publish_twist = self.create_publisher(Twist, '/model/eddiebot/cmd_vel', 10)
        self.kinect_data = self.create_subscription(
            Image,
            '/kinect_rgbd_camera/image',
            self.feedback,
            10)
        self.timer = self.create_timer(0.1, self.action)
        self.kinect_data  # prevent unused variable warning
        self.end = False 
        #  in situation variable we consider f for forward , y for yellow , g for green and r for red
        self.situation = 'f'
        self.number_of_rotate = 0
        self.forward_angle = 0


    
    def action(self):

        cmd = Twist()
        if self.situation == 'f'  :
            cmd.linear.x = 1.0
            cmd.angular.z = -0.01 * self.forward_angle
            
        elif self.situation == 'y' :
            # we have to turn left for 90 degree 
            # for doing this we have to rotate with speed of 1 for approximately 28 times
            cmd.angular.z = -1.0
            cmd.linear.x = 0.0
            
            
            self.number_of_rotate += 1
            if self.number_of_rotate == 34 :
                self.situation = 'f'
                self.number_of_rotate = 0
        elif self.situation == 'r' :
            # we have to turn left for 90 degree 
            # for doing this we have to rotate with speed of 1 for approximately 28 times
            cmd.angular.z = 1.0
            cmd.linear.x = 0.0
            
            
            self.number_of_rotate += 1
            if self.number_of_rotate == 34 :
                self.situation = 'f'
                self.number_of_rotate = 0
        elif self.situation == 'g' :
            cmd.angular.z = 0.5
            self.end = True
           
        self.publish_twist.publish(cmd)
    def feedback(self, msg):
        height = msg.height
        width = msg.width

                    
        channel = msg.step//msg.width
        image = np.reshape(msg.data, (height, width, channel))

        if self.end == False :
            if image[ : , : , 2 ].max() < 25 :# it means that the picture is not blue 

                if image[: , : , 1 ].max() < 25 :# the picture is also not green so it is red
                    self.situation = 'r'
                    print("red")
                elif image[:, : ,0].max() < 25 : # the picture is also not red
                    self.situation = 'g'
                    print("green")
                else: 
                    self.situation = 'y'
                    print("yellow")
            else :
                 # here we have to design an strategy to guide our agent tword the center of the box 
            # to do that we consider the number of pixels infront of the agent that is not blue , it 
            # means that the values of its pixels of its cahnnel  have to be lower than 25 , so it illustrates that
            # that the pixel is not blue so it can be red , green or yellow and it dosnt matter what the color 
            # is , the critical thing is that the pixele is not blue. second we calculate the diffrence between 
            # number of pixlels .and guide our agent to go tward the side that have more number of non-blue pixels .
                middle = image[int(height/2), :, 2]
                left_pixels = middle[0:int(width/2)]
                right_pixels = middle[int(width/2):]            
                
                nubmers_of_left= (left_pixels<25).sum()
                nubmers_of_rite= (right_pixels<25).sum()
                        
                self.forward_angle = nubmers_of_rite - nubmers_of_left
            

        if self.end == True :
            self.situation = 'end' 

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
