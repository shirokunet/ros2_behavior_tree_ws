# ros2_behavior_tree_ws
Minimal workspace for learning behavior tree for ROS2.

## Dependency
- ROS2 Dashing Diademata
- BehaviorTree.CPP 2.5.1

## Build and Run
```
$ colcon build
$ . install/local_setup.bash
$ ros2 run behavior_trees_hello_world factory_tree
Robot says: "Hello!!!"
GripperInterface::open
ApproachObject: approach_object
GripperInterface::close
```

## Reference
- [BehaviorTree.CPP/examples/t02_factory_tree.cpp](https://github.com/BehaviorTree/BehaviorTree.CPP/blob/f9dbe9d4403801d0e14c4eb707c98e99a9e21efd/examples/t02_factory_tree.cpp)
