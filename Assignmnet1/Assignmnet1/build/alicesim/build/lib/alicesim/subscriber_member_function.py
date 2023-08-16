import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class MinimalSubscriber(Node):

    key = "9812762758"
    counter = 0
    message =[]
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
    	enter = 1
    	
    	if msg.data[0] ==',':
    		
    		result = [(ord(a) ^ ord(b)) for a, b in zip(self.key, self.message)]
    		result = [chr(a) for a in result] 
    		string = ''
    		for i in range (len(result)):
    			string +=result[i]
    		msg.data = string

    		self.get_logger().info('I heard: "%s"' % msg.data)
    		self.message = []
    		
    		self.counter = 0
    		enter = 0
    		quit()
    	if enter == 1 :
    		self.message.append(msg.data[0])
    		
    	
    	
        	


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
