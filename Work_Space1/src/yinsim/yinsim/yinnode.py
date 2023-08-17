
import rclpy

from  interfaces.srv import  FirstSreviceMessage
from interfaces.msg import FirstMsgMessage
from rclpy.node import Node
import string

class MinimalService(Node):
    yin_messages = [
        "I am Yin, some mistake me for an actual material entity but I am moreof a concept",
        "Interesting Yang, so one could say, in a philosophical sense, we aretwo polar elements",
        "We, Yang, are therefore the balancing powers in the universe.",
        "Difficult and easy complete each other.",
        "Long and short show each other.",
        "Noise and sound harmonize each other.",
        "You shine your light."
        ]
    isClient = True 
    stage = 0
    
    def __init__(self):
        super().__init__('yin')
        self.srv = self.create_service(FirstSreviceMessage, 'yin_service', self.message)
        self.publisher_ = self.create_publisher(FirstMsgMessage, 'conversation', 10)
        time_priod = 0.5
        self.timer = self.create_timer(time_priod , self.callbackClient)

    def callbackClient(self):
        if self.isClient: 
            client_ = self.create_client(FirstSreviceMessage,"yang_srv" )
           

            self.req = FirstSreviceMessage.Request()
            self.req.message = self.yin_messages[self.stage]
            self.req.len = len(self.yin_messages[self.stage])


            while not client_.wait_for_service(timeout_sec=1.0):
                self.get_logger().info('service not available, waiting again...')

           
            self.stage += 1
            self.isClient = False
            future = client_.call_async(self.req)
            response = future.result()
            future.add_done_callback(self.call_back_done_client)

    def call_back_done_client(self , future):
        try:
            response = future.result()       
            self.get_logger().info( self.yin_messages[self.stage -1]+"response= " + str(response.result))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))


    def message (self, request  , response):
        message = request.message
        lenght =  request.len
        response.result  = self.calc_ascii(message)
        data = FirstMsgMessage()
        data.message = "yang said :" + message + "length -> " + str(lenght) + "checksum -> " + str(response.result) 
        self.publisher_.publish(data)
        self.isClient = True
        return response

        # self.get_logger().info(io)
        # self.publisher_.publish(io)

        
    def timer_callback(self)  :
        msg = FirstSreviceMessage()
        self.publisher_.publish()

    def calc_ascii(self,text):
        ascii_sum = 0
        words = text.split()
        for sub in words:
            for ele in sub :
                ascii_sum += (ord(ele))  
        return ascii_sum    
def main(args = None):
    rclpy.init(args=args)

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
