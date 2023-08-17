
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


class TalkerQos(Node):

    def __init__(self, qos_profile):
        super().__init__('talker_qos')
        self.i = 0
        if qos_profile.reliability is QoSReliabilityPolicy.RELIABLE:
            self.get_logger().info('Reliable talker')
        else:
            self.get_logger().info('Best effort talker')
        self.pub = self.create_publisher(String, 'chatter', qos_profile)

        timer_period = 1.0
        self.tmr = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: {0}'.format(self.i)
        self.i += 1
        self.get_logger().info('Publishing: "{0}"'.format(msg.data))
        self.pub.publish(msg)


def main(argv=sys.argv[1:]):
   
    rclpy.init(args=argv)

   
    custom_qos_profile = QoSProfile(
            depth=10,
            reliability=QoSReliabilityPolicy.RELIABLE)
    node = TalkerQos(custom_qos_profile)

    cycle_count = 0
    rclpy.spin_once(node)
         
    node.destroy_node()
    rclpy.try_shutdown()


if __name__ == '__main__':
    main()
