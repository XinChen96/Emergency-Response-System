TEMPLATE = subdirs
 
  SUBDIRS = \
            users \
	    db    \
	    gui
 
  # build the project sequentially as listed in SUBDIRS !
  CONFIG += ordered
