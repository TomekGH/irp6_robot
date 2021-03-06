#ifndef Irp6pmJ2M_H_
#define Irp6pmJ2M_H_

#include <rtt/TaskContext.hpp>
#include <rtt/Port.hpp>
#include <Eigen/Dense>

class Irp6pmJ2M: public RTT::TaskContext {
public:
  Irp6pmJ2M(const std::string& name);
	virtual ~Irp6pmJ2M();

	bool configureHook();
	void updateHook();
private:
	bool i2mp(const double* joints, double* motors);
	bool checkMotorPosition(const double * motor_position);
	RTT::InputPort<Eigen::VectorXd> port_joint_position_;
	RTT::OutputPort<Eigen::VectorXd > port_motor_position_;

	Eigen::VectorXd motor_position_, joint_position_;
};

#endif /* Irp6pmJ2M_H_ */
