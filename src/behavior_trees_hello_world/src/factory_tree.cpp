#include "behaviortree_cpp/xml_parsing.h"
#include "behaviortree_cpp/blackboard/blackboard_local.h"
#include "behavior_trees/dummy_nodes.h"

using namespace BT;

// clang-format off
const std::string xml_text = R"(

 <root main_tree_to_execute = "MainTree" >

     <BehaviorTree ID="MainTree">
        <Sequence name="root_sequence">
            <SayHello       name="action_hello"/>
            <CheckBattery/>
            <Sequence>
                <OpenGripper    name="open_gripper"/>
                <ApproachObject name="approach_object"/>
                <CloseGripper   name="close_gripper"/>
            </Sequence>
        </Sequence>
     </BehaviorTree>

 </root>
 )";

// clang-format on

int main()
{
    BehaviorTreeFactory factory;

    using namespace DummyNodes;

    factory.registerSimpleAction("SayHello", std::bind(SayHello));
    factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));
    factory.registerSimpleCondition("CheckTemperature", std::bind(CheckTemperature));

    GripperInterface gripper;
    factory.registerSimpleAction("OpenGripper", std::bind(&GripperInterface::open, &gripper));
    factory.registerSimpleAction("CloseGripper", std::bind(&GripperInterface::close, &gripper));

    factory.registerNodeType<ApproachObject>("ApproachObject");

    // IMPORTANT: when the object tree goes out of scope, all the TreeNodes are destroyed
    auto tree = buildTreeFromText(factory, xml_text);

    // The tick is propagated to all the children.
    // until one of the returns FAILURE or RUNNING.
    // In this case all of the return SUCCESS
    tree.root_node->executeTick();

    return 0;
}
