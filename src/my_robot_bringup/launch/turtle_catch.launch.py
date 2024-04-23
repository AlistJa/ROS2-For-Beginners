from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

#    remap_number_topic = ("number", "my_number")

    turtle_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="turtlesim_node"
    )

    turtle_controller_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_controller",
        name="turtle_controller",
        parameters=[
            {"linear_speed_gain": 2.0},
            {"angular_speed_gain": 6.0}
        ]
    )

    turtle_spawner_node = Node(
        package="turtlesim_catch_them_all",
        executable="turtle_spawner",
        name="turtle_spawner",
        parameters=[
            {"spawn_rate": 1.2}
        ]
    )

    ld.add_action(turtle_node)
    ld.add_action(turtle_controller_node)
    ld.add_action(turtle_spawner_node)
    return ld