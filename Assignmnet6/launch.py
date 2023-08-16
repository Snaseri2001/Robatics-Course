from launch_ros.actions import Node
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.launch_description_sources import AnyLaunchDescriptionSource

import os
from ament_index_python import get_package_share_directory
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription, TimerAction)
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node, PushRosNamespace


# Set path to RViz config file
rviz2_config =  os.path.join( os.getcwd(), 'config', 'my_config.rviz')
# static_transforms = [
#         {
#             'translation': (0.0, 0.0, 0.0),
#             'rotation': (0.0, 0.0, 0.0, 1.0),
#             'parent_frame_id': 'eddiebot/base_footprint',
#             'child_frame_id': 'base_footprint'
#         },
#         {
#             'translation': (0.0, 0.0, 0.0),
#             'rotation': (0.0, 0.0, 0.0, 1.0),
#             'parent_frame_id': 'world',
#             'child_frame_id': 'eddiebot/odom'
#         },
#         {
#             'translation': (0.0, 0.0, 0.0),
#             'rotation': (0.0, 0.0, 0.0, 1.0),
#             'parent_frame_id': 'camera_link',
#             'child_frame_id': 'camera_depth_frame'
#         }
#     ]
# static_transform_publisher_nodes = []
# for static_transform in static_transforms:
#         transform_stamped = TransformStamped()
#         transform_stamped.header.frame_id = static_transform['parent_frame_id']
#         transform_stamped.child_frame_id = static_transform['child_frame_id']
#         transform_stamped.transform.translation.x = static_transform['translation'][0]
#         transform_stamped.transform.translation.y = static_transform['translation'][1]
#         transform_stamped.transform.translation.z = static_transform['translation'][2]
#         transform_stamped.transform.rotation.x = static_transform['rotation'][0]
#         transform_stamped.transform.rotation.y = static_transform['rotation'][1]
#         transform_stamped.transform.rotation.z = static_transform['rotation'][2]
#         transform_stamped.transform.rotation.w = static_transform['rotation'][3]

# ARGUMENTS = [
#         DeclareLaunchArgument(
#             'use_sim_time',
#             default_value='false',
#             description='Use simulation (Gazebo) clock if true'),
#         DeclareLaunchArgument(
#             'description',
#             default_value='true',
#             description='Launch eddiebot description'
#             ),
#         DeclareLaunchArgument('model', default_value='eddie_kinect_v1',
#                               choices=['eddie_kinect_v1'],
#                               description='Eddiebot Model'),
#         DeclareLaunchArgument(
#             'namespace',
#             default_value='',
#             description='Robot namespace'
#             ),
# ]
# namespace = LaunchConfiguration('namespace')


def generate_launch_description():


    # pkg_eddiebot_viz = get_package_share_directory('eddiebot_rviz')
    # pkg_eddiebot_description = get_package_share_directory('eddiebot_description')

    # description_launch = PathJoinSubstitution(
    #     [pkg_eddiebot_description, 'launch', 'robot_description.launch.py']
    # )
    return LaunchDescription([

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('eddiebot_gazebo'),
                             'launch/eddiebot_gz_sim.launch.py')
            ),
            launch_arguments={'world': 'maze_marked'}.items()
        ),

    

        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/model/eddiebot/tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V'],
            remappings=[
                ('/model/eddiebot/tf', 'tf'),
            ],
            output='screen'
        ),        

        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/kinect_rgbd_camera/camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo'],
            output='screen'
        ),

        Node(
            package='ros_gz_bridge', 
            executable='parameter_bridge', 
            name='parameter_bridge',
            arguments=['/kinect_rgbd_camera/depth_image@sensor_msgs/msg/Image@gz.msgs.Image'],
            output='screen'
        ),

        Node(
            package='depthimage_to_laserscan', 
            executable='depthimage_to_laserscan_node', 
            name='depthimage_to_laserscan',
            remappings=[
                ('depth_camera_info' ,'/kinect_rgbd_camera/camera_info'),
                ('depth' ,'/kinect_rgbd_camera/depth_image'),
            ],
            output='screen'
        ),  
        # PushRosNamespace(namespace),


        Node(package='rviz2',
             executable='rviz2',
             name='rviz2',
             arguments=['-d', rviz2_config],
             remappings=[
                ('/tf', 'tf'),
                ('/tf_static', 'tf_static')
             ],
             output='screen'),
        # # TimerAction(
        #     period=1.0,
        #     actions=[
        #         IncludeLaunchDescription(
        #             PythonLaunchDescriptionSource([description_launch]),
        #             launch_arguments=[('model', LaunchConfiguration('model')),
        #                               ('use_sim_time', LaunchConfiguration('use_sim_time'))],
        #         )])

# Define a function to launch RViz

        # Node(
        #     package='rviz2',
        #     executable='rviz2',
        #     arguments=['-d', rviz_config_file],
        #     output='screen') ,
    



         # Define the static transforms to be published


    # Create nodes to publish the static transforms
    
        # Node(
        #     package='tf2_ros',
        #     executable='static_transform_publisher',
        #     arguments=[
        #         str(static_transform['translation'][0]),
        #         str(static_transform['translation'][1]),
        #         str(static_transform['translation'][2]),
        #         str(static_transform['rotation'][0]),
        #         str(static_transform['rotation'][1]),
        #         str(static_transform['rotation'][2]),
        #         static_transform['parent_frame_id'],
        #         static_transform['child_frame_id']
        #     ],
        #     remappings=[('input', '/tf_static')],
        #     output='screen'
        # ) ,
        # static_transform_publisher_node._node.add_publisher(StaticTransformBroadcaster(transform_stamped)) ,

        # static_transform_publisher_nodes.append(static_transform_publisher_node) ,

# ros2 run tf2_ros static_transform_publisher "0" "0" "0" "0" "0" "0""eddiebot/base_footprint" "base_footprint"
# ros2 run tf2_ros static_transform_publisher "0" "0" "0" "0" "0" "0""world" "eddiebot/odom"
# ros2 run tf2_ros static_transform_publisher "0" "0" "0" "0" "0" "0""camera_link" "camera_depth_frame"






    ])



    
    