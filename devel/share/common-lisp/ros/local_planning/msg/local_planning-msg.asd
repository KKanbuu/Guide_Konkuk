
(cl:in-package :asdf)

(defsystem "local_planning-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MyFirstMsg" :depends-on ("_package_MyFirstMsg"))
    (:file "_package_MyFirstMsg" :depends-on ("_package"))
  ))