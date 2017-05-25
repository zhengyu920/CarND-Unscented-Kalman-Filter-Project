#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */
    VectorXd rmse(4);
    rmse << 0,0,0,0;

    // check the validity of the following inputs:
    //  * the estimation vector size should not be zero
    //  * the estimation vector size should equal ground truth vector size
    if(estimations.size() == 0 || estimations.size() != ground_truth.size()){
        std::cout<<"estimations size error"<<std::endl;
        return rmse;
    }
    //accumulate squared residuals
    for(int i=0; i < estimations.size(); ++i){
        VectorXd res = 	estimations[i] - ground_truth[i];
        res = res.array()*res.array();
        rmse = rmse + res;
    }

    //calculate the mean
    rmse = rmse/ground_truth.size();
    //calculate the squared root
    rmse = rmse.array().sqrt();
    //return the result
    return rmse;
}
