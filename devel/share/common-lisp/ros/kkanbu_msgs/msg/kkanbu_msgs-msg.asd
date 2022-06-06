
(cl:in-package :asdf)

(defsystem "kkanbu_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :nav_msgs-msg
)
  :components ((:file "_package")
    (:file "ControlCommand" :depends-on ("_package_ControlCommand"))
    (:file "_package_ControlCommand" :depends-on ("_package"))
    (:file "LandmarkPath" :depends-on ("_package_LandmarkPath"))
    (:file "_package_LandmarkPath" :depends-on ("_package"))
    (:file "LandmarkPoint" :depends-on ("_package_LandmarkPoint"))
    (:file "_package_LandmarkPoint" :depends-on ("_package"))
    (:file "LocalPathArray" :depends-on ("_package_LocalPathArray"))
    (:file "_package_LocalPathArray" :depends-on ("_package"))
    (:file "SensorPoint" :depends-on ("_package_SensorPoint"))
    (:file "_package_SensorPoint" :depends-on ("_package"))
    (:file "SensorPointArray" :depends-on ("_package_SensorPointArray"))
    (:file "_package_SensorPointArray" :depends-on ("_package"))
    (:file "VehicleState" :depends-on ("_package_VehicleState"))
    (:file "_package_VehicleState" :depends-on ("_package"))
  ))