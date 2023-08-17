import argparse
import sys

import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from rclpy.qos import QoSProfile
from rclpy.qos import QoSReliabilityPolicy
from rclpy.utilities import remove_ros_args

from std_msgs.msg import String


class ListenerQos(Node):

    def __init__(self, qos_profile):
        super().__init__('listener_qos')
        if qos_profile.reliability is QoSReliabilityPolicy.RELIABLE:
            self.get_logger().info('Reliable listener')
        else:
            self.get_logger().info('Best effort listener')
        self.sub = self.create_subscription(
            String, 'chatter', self.chatter_callback, qos_profile)
    def chatter_callback(self, msg):
        self.get_logger().info('I heard: [%s]' % msg.data)


def main(argv=sys.argv[1:]):
   
    rclpy.init(args=argv)

    
    custom_qos_profile = QoSProfile(
            depth=10,
            reliability=QoSReliabilityPolicy.RELIABLE)
   
    node = ListenerQos(custom_qos_profile)

   
    
    rclpy.spin_once(node)
   
    node.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()
