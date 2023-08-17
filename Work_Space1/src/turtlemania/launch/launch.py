import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
  	) ,
  
  	Node(
  	    package = 'turtlemania',
  	    executable = 'brodcaster',
  	    name = 'brodcaster1',
  	    parameters=[{
  	    	'turtlename':'turtle1' }]
  	    	
  	
  	),
  	Node(
  	    package = 'turtlemania',
  	    executable = 'listener',
  	    name = 'listener1',
  	    parameters=[
  	    	{'target':'turtle1'} , 
  	    	{'source', 'turtle2'} ,
  	    	]
  	    	
  	
  	),
  		Node(
  	    package = 'turtlemania',
  	    executable = 'brodcaster',
  	    name = 'brodcaster2',
  	    parameters=[{
  	    	'turtlename':'turtle2' }]
  	    	
  	
  	),
  	Node(
  	    package = 'turtlemania',
  	    executable = 'listener',
  	    name = 'listener2',
  	    parameters=[
  	    	{'target':'turtle2'} , 
  	    	{'source', 'turtle3'} ,
  	    	]
  	    	
  	
  	),
  	Node(
  	    package = 'turtlemania',
  	    executable = 'brodcaster',
  	    name = 'brodcaster3',
  	    parameters=[{
  	    	'turtlename':'turtle13' }]
  	    	
  	
  	),
  	Node(
  	    package = 'turtlemania',
  	    executable = 'listener',
  	    name = 'listener3',
  	    parameters=[
  	    	{'target':'turtle3'} , 
  	    	{'source', 'turtle4'} ,
  	    	]
  	    	
  	
  	),
  	Node(
  	    package = 'turtlemania',
  	    executable = 'brodcaster',
  	    name = 'brodcaster4',
  	    parameters=[{
  	    	'turtlename':'turtle4 '}]
  	    	)
  	    	
  	])
