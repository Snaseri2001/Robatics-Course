from launch_ros.actions import Node
from launch import LaunchDescription

def generate_launch_description():
    return LaunchDescription([
    
        
        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/cmd_vel@geometry_msgs/msg/Twist@gz.msgs.Twist'],
            output='screen'
        ),

        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/lidar@sensor_msgs/msg/LaserScan@gz.msgs.LaserScan'],
            output='screen'
        ),        

        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/robot_tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V'],
            remappings=[
                ('/robot_tf', '/tf'),
            ],
            output='screen'
        ),        

        Node(
            package='tf2_ros', 
            executable='static_transform_publisher', 
            name='static_transform_publisher',
            arguments=["0", "0", "0", "0", "0", "0", "vehicle_blue/chassis", "vehicle_blue/chassis/gpu_lidar"],
            output='screen'
        ),        

        Node(
            package='tf2_ros', 
            executable='static_transform_publisher', 
            name='static_transform_publisher',
            arguments=["0", "0", "0", "0", "0", "0", "world", "vehicle_blue/odom"],
            output='screen'
        ),        
        
    ])