[33mcommit ccf07e6e300718c7982b431fd923142325541168[m[33m ([m[1;36mHEAD -> [m[1;32mmaster[m[33m, [m[1;31morigin/master[m[33m, [m[1;31morigin/HEAD[m[33m, [m[1;32mmerger[m[33m)[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 11:48:47 2018 -0400

    fixed all the missing methods

[33mcommit 43fffff3569454bae585d16db3ac7a21b9ced86a[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 00:32:38 2018 -0400

    trying to merge

[33mcommit f7dc7427ca7f1b9fa0bccb30872c34873bf43158[m
Merge: a8ac67b fd84db6
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 00:27:23 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit a8ac67b01aa9e3b373c5c9cbe02cf925fbb6b1e3[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 00:27:19 2018 -0400

    merging

[33mcommit d6714d0d2f1470c6faaa3b342ac36df5236aab52[m
Merge: 78d63d0 4dbaeda
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 00:26:56 2018 -0400

    merging

[33mcommit fd84db67767b347d4ebe5d6e412ef51c936a3a76[m
Merge: f6825ac 4dbaeda
Author: Chen Xin <xinc@lafayette.edu>
Date:   Thu Apr 26 00:24:32 2018 -0400

    Merge branch 'master' of 139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit f6825aca9a655c662504db1e80350cb7a360150f[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Thu Apr 26 00:24:21 2018 -0400

    Added funtion to prevent creation of duplicate groups. Solved warnings from qsqldatabase that now we close old connection everytime we establish new connection

[33mcommit 78d63d0b28ace27a190cf9351dbe1f4eff6f3876[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 26 00:13:11 2018 -0400

    used mutex to lock threading, now instructions can be updated on the go

[33mcommit 4dbaeda8676d5098bafce22a2ea591a8ac63604a[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 23:16:25 2018 -0400

    Made slight changes to the code.

[33mcommit 0e6710b7a24cdaf99aaceebab64ba0652e88e100[m
Merge: 76d6063 0c61e77
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 22:52:52 2018 -0400

    Merge branch 'master' of 139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 76d606314d0d4262c470f6fc355630c5cf27f4f3[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 22:52:45 2018 -0400

    Solved conflicts where one group has multiple users and one user is assigned to multiple group. Updated group member page and function to display more user information

[33mcommit 0c61e77bd886c43485b067183a550b8bdf6288b2[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 22:37:58 2018 -0400

    Added in capability for first responders to receive notifications. If the first resonders group is not a part of the active emergency they should not recieve a notification.

[33mcommit 280b92e736e90dcb1f6dc81a4e40c0f4b8572c0e[m
Merge: ba7afd1 3f17ae9
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 21:24:28 2018 -0400

    fixed merge conflict

[33mcommit ba7afd1da02977bcf67fad8c8967977206def64d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 21:22:09 2018 -0400

    Got notifications working for civilians for a simulation. If a user signs in during a simulation, inputs their lat, lng, the notification will appear.

[33mcommit 3f17ae9be095a4a2950204f7b79f083640bd46bf[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 20:56:50 2018 -0400

    mac dir fix

[33mcommit 4b5fb90d59f22bc2aeaa9d595b0f9a596c11b65a[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 20:33:03 2018 -0400

    return not assigned if the selected responder is not in a group

[33mcommit fd6443d792f4756f7e7a3a8dae1edf7213599f15[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 20:22:53 2018 -0400

    added function to find which group a specific responder belongs to

[33mcommit 19d454b61a8b4055a313eb8884ba3e2e324167b3[m
Merge: 7ad2c7a 688b462
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 20:04:35 2018 -0400

    Merged

[33mcommit 7ad2c7ad3c291449fff821f804a2b846b24548ed[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 19:59:14 2018 -0400

    update database function to find group

[33mcommit 688b4626aef14aae14d8095dbcd3247d1e3a4946[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 19:49:36 2018 -0400

    Added a feature so simulation can still be run after the software is closed. This deals with accessing the database properly as the program is opened.

[33mcommit 8b795a9c8d8296c6a2e844bfc54882480a03188d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 19:32:13 2018 -0400

    Fixed the viewing bug so now the viewer will properly display the protocol after accessing the database.

[33mcommit 2f3add0fea8d548ded39759a5981a44326b253c0[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 25 17:56:42 2018 -0400

    fixed many build errors after merge

[33mcommit 938a1e0660528445d99a6c38c2cbfe1623aee3ed[m
Merge: 4dae086 b812e2a
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 25 17:44:58 2018 -0400

    very arduous merge

[33mcommit 4dae0868bdd317b14fc6eb67d0a0c0b40ab13c94[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 25 17:38:17 2018 -0400

    Functional server and client

[33mcommit b812e2abfee24a8d84d1f63ae85cf1801d5af7f8[m
Merge: 6260750 6aa6aef
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 16:55:48 2018 -0400

    Merge branch 'master' of 139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xi

[33mcommit 6260750235f708385bb68b865d25a30ea512ace2[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 16:55:41 2018 -0400

    merge

[33mcommit 6aa6aefcb6621e26201b2286e92d882eaa9cdf60[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 16:52:56 2018 -0400

    Added creation notification from gui successfully. It will add it to the database and remove it when the button is pressed. Also displays on screen text informing the user if it is active.

[33mcommit d3d94cac51b5cf13887368d5ab83e2185cd5e082[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 25 15:16:35 2018 -0400

    Pushed error fix for viewer.

[33mcommit feff994f13d2ce4f2426acd73f9fa56054c2d1e1[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Wed Apr 25 00:10:43 2018 -0400

    Added functino to convert foreign key number to the data that it reference

[33mcommit 51db5326de79fa45417dc33f403657bdbb9edbf0[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 21:38:16 2018 -0400

    mac directroy fox

[33mcommit 66559bff9efd59a75d51dfa5c7f63406f3db0717[m
Merge: f0b64a4 d00a7a9
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 21:31:09 2018 -0400

    added functions to remove members from a responder group

[33mcommit f0b64a46fc917caf33e1b01f4772c024cd6c1b9e[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 21:11:41 2018 -0400

    added new pages and functions  to manipulate responder group and members inside it. New function to delete groups and manage groups by adding members

[33mcommit d00a7a97915caa056a7b259efaf6b8ac224d0546[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 19:21:26 2018 -0400

    Fixed the visual appearance of some text in the GUI.

[33mcommit dba8422961f7cace48dabf0e5951f86a0e8150f3[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 18:55:22 2018 -0400

    Created a container for Notifications, then created the Notification database, and then tested it (it worked).

[33mcommit f9f7572b1c33e0a71815c4c758bb2537cecccb0a[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 18:13:52 2018 -0400

    Created the GUI area for the Notification checking.

[33mcommit 6d8cba8aa154a084da0a21d34e088ef17d1459e8[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 17:57:43 2018 -0400

    Adding in feature to only display groups that have a response for the emergency. Also fixed a bug in the response database.

[33mcommit 0a407e413e6903e6c3aa1667fc7369c1230be721[m
Merge: c8f265f bfb2e7a
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 16:41:58 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit c8f265f7c4d63047722a1ab439eeef372a9e646c[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 16:41:55 2018 -0400

    Adding manueverability between the new View Protocol page and it can now access the database to display the correct information.

[33mcommit bfb2e7a0c420fd0ed56ff2f1ff368d5c4b56338d[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 16:16:50 2018 -0400

    mac dir fix

[33mcommit 0a16f66d8bb5ab86281cf76271335fd04325ebd9[m
Merge: 6c830a1 7b11512
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 16:15:35 2018 -0400

    Merge

[33mcommit 6c830a1bb9185b74e7965c830eefbf3c8fa01d9c[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 16:14:52 2018 -0400

    Added qsqlrelationaltablemodel to apply foreign key functions

[33mcommit 7b115123472c247f18f3b666b940b53cbbba49ce[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 15:54:46 2018 -0400

    Adding Viewing Protocols option to the GUI.

[33mcommit a1ab4c559f6f1379d706d6be6bd06a5995fa1ad8[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 15:23:38 2018 -0400

    Fixing some parts that were left out in the last merge. Added new group to combo boxes.

[33mcommit 1352d6f3121c23f81f207aef03a3d00c5b696305[m
Merge: c15d6b5 366b257
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 12:46:45 2018 -0400

    merge

[33mcommit c15d6b5667b26cde8114d318b77d5cb5930ae4e6[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 12:43:15 2018 -0400

    responder group table view set up

[33mcommit 366b25728fb4e6da9de6922c478775de662eb926[m
Merge: 858345f 41ba608
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 12:40:00 2018 -0400

    Fixed merge conflict.

[33mcommit 858345faa2c8bbd854fca2d23437f5bf7714bddb[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 12:39:00 2018 -0400

    Fixed issue with responses db

[33mcommit 41ba6083cf80d122dbdc82d10c8d84b7127c2ef6[m
Merge: 22d8448 7e545fb
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 12:35:55 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 22d844823448953439305f1af88745db37386bbb[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 12:35:46 2018 -0400

    fixed the gosh darn bug

[33mcommit 7e545fb19d72a48a26b298b67abc98863630dfd6[m
Merge: 856d143 1ab1ceb
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 12:10:56 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 856d143ede2c9f2f5d9455b2429f6322e415fafd[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 12:10:52 2018 -0400

    Commiting changes.

[33mcommit 1ab1ceb8544bc67c302d5affc70b50b594fe7fa9[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 12:09:58 2018 -0400

    trying to fix the add response db

[33mcommit 6b35a372916c2aabfc65a508e50c9ac5f91de8d1[m
Merge: df905cc 7c53271
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 11:53:12 2018 -0400

    merged

[33mcommit df905cc020c691c8ee80a63b7577761a0d9dcd74[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 11:50:15 2018 -0400

    time to pull

[33mcommit 7c53271b25a5588f7f4cf6f31fa4b3923e1bffea[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 11:46:21 2018 -0400

    fixed menu error

[33mcommit d580025d83041278d99bca34a7352ac0acd0e4f0[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 11:44:27 2018 -0400

    Fixing slight issues and merge errors.

[33mcommit 33ba64c9c0b2c73e7d0811d323360548c8c1cb12[m
Merge: 87e7882 d3a4547
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 11:38:04 2018 -0400

    Fixed merge conflict

[33mcommit 87e78823338a6030f1f81449db4d2886e2281826[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 24 11:33:07 2018 -0400

    Pushing changes for ben.

[33mcommit d3a454794b93b9b0dd6350340782f744e401026d[m
Merge: 6cadaa2 4690c1a
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 11:27:26 2018 -0400

    Merge

[33mcommit 6cadaa2f00d64c6082d65b3957f46894b9184d41[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 11:26:08 2018 -0400

    get all types of database by a controller function

[33mcommit 4690c1a3c934df72ece1d81309dfc1237f66fe8b[m
Merge: 115be46 83b2292
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 11:22:18 2018 -0400

    merged

[33mcommit 115be4696bd6f76217608186824cf8c9538412bf[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 24 11:19:58 2018 -0400

    started work on sockets communication

[33mcommit 83b229206e77cb60cecdf4b3d2ae0122abcd1a78[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 10:44:08 2018 -0400

    Switched from tab widget to combox widget for viewing database table. This significantly reduced the amount of code written for methods and pointers produced. GUI class now looks cleaner

[33mcommit 03ff70a3d2e19636a14f5f1398e16fcfda7de8aa[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 10:05:11 2018 -0400

    Commented and rearranged parts of gui class. Simplified login method.

[33mcommit 7bcc27b2bf8e9092c5ca79b9e5805a54c3253c2e[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 01:21:18 2018 -0400

    Mac directory fix again

[33mcommit fc8d1519fd58a42b2e2cf4c7ad34d59b41d131c1[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 01:20:37 2018 -0400

    updates tableview to have evenly streched colomn (which looks so satisfying)

[33mcommit 82e94f591d79b5f07e8f8e5e50e1b5357b152905[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 01:13:47 2018 -0400

    reload button clear delete alert

[33mcommit 3d433d73b15e90f1a47479e1ec5c49531a064d7e[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Tue Apr 24 00:57:59 2018 -0400

    Finished up view/delete user page and all related functions and ui changes

[33mcommit 1e1d7ba946a6969b4894e8d388f6b449f26f928d[m
Merge: b519477 c478f38
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 21:35:35 2018 -0400

    Merged with updated delete funciton

[33mcommit b5194778b1ccc002fce5f02ad9477a5367d3037a[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 21:31:10 2018 -0400

    added function to read username from selected row from table view

[33mcommit c478f3828c98129c6946ebdc37bd6be11ec1c810[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 21:26:02 2018 -0400

    Making sure code compiles after big merge conflict. Modified small items.

[33mcommit 3c78d75de44dae4efcb60795d8958d5b200e8e7a[m
Merge: 4e55673 39394d6
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 21:23:01 2018 -0400

    fixed merge conflict

[33mcommit 4e556736a63eb2ed724365315863b3b388950a96[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 21:13:40 2018 -0400

    Added in all GUI and movement through menus for adding in group roles. Also added in the functionality for when you add a role it adds it to the response database. This is linked to the GUI area that was jsut created.

[33mcommit 39394d6fa4166e2294d578b67f1a00b1b4e7db08[m
Merge: fdbcfc6 fcee098
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 19:58:00 2018 -0400

    Merged and database tableview updates

[33mcommit fdbcfc659fce37facabbdec4dc0d19e112f2ce17[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 19:51:44 2018 -0400

    added viewing table for emergency planner

[33mcommit fcee0986c155fbf868fb0ab3372237e6343e5f05[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 19:20:31 2018 -0400

    Fixed the simulation database so the foreign key now works with information selected in the combo box. This also goes for viewing the simulation as well.

[33mcommit 708e0c05b1f29130431773d99ab269feae4ee3d7[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 18:40:59 2018 -0400

    I fixed the error and made sure the emergency tables were properly built on execution of the program. I also made sure the Emergencies from the database would be added to the combobox on startup of the program.

[33mcommit d56cb5ff83113ab1efa1d0a18886c977af92fd49[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 17:45:34 2018 -0400

    Add viewing user function to display all users

[33mcommit 1cf1f3460ec8641391d4d0b0aa96678dc8b6a9c6[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 17:19:03 2018 -0400

    mac direcotory change fix

[33mcommit 4f628135c972aecbfee4b5c5b588ac7ba4835efa[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 17:18:31 2018 -0400

    planner can view users in database seperately through table view and qsqltable model. sorted in alphabet order

[33mcommit 558d0381a685a65a0b8e485b5b291fac5f905bcd[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 16:33:33 2018 -0400

    mac directory issur

[33mcommit 850eb8345a27bb72d25b67cddabd0198e7f505b9[m
Merge: baa5fdf ac2f511
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 16:27:17 2018 -0400

    Merged and updated delete user ui page and buttons navigation

[33mcommit baa5fdf902fa714c14664e76554a07025ced0db9[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 16:18:11 2018 -0400

    qsqltablemodel added for civilian and responder

[33mcommit ac2f511a1db7f4be13fec8529c72501063598c01[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 16:14:18 2018 -0400

    just updating the code on the repo

[33mcommit 86137ca290f3a5814f540020ab209cfb39a25c39[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 16:05:54 2018 -0400

    fixing some other merging errors.

[33mcommit 43608c94bbdaf2b43f1227b34e8ec6b10332f69b[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 15:54:49 2018 -0400

    fixed path

[33mcommit 7c4aea0cceea495f321a6a64e8cd9ba8095aff61[m
Merge: ba6a947 161fedf
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 15:53:41 2018 -0400

    fixed merge conflict

[33mcommit ba6a9478139608c4f51faa280f4852d88b3f2a66[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 15:51:21 2018 -0400

    Have datasbase entries be added into combo boxes from the beginning. Fixed viewing error.

[33mcommit 161fedf940ae5d739f9aec67c4a21bd0002d47d7[m
Merge: 26d34a0 064b004
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 15:51:07 2018 -0400

    merged

[33mcommit 26d34a01ace86663d79cd11957d19d72dc80bd07[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 15:50:29 2018 -0400

    added response db

[33mcommit 064b004a664f1e7fecd11e721cd91a2030d0d204[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 15:34:16 2018 -0400

    update ui pages for deleting users

[33mcommit 9b4f26e09c9d49800191538d778f50a763c6052e[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 15:02:49 2018 -0400

    ui updates to add delete use and rearrange menu buttons

[33mcommit c7ee847c13d946fbb9c30d9db63ae8d437ffe0ae[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Mon Apr 23 14:48:34 2018 -0400

    compile issue from mainwindow

[33mcommit 9eac8c3f2ba947b23e3d40dbbf599d67cd15c232[m
Merge: 13acf8a 0e9ac7c
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 14:40:35 2018 -0400

    Fixed merge conflict

[33mcommit 13acf8a8d5e8976a5b60e149624d9c957f4620e3[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 14:39:04 2018 -0400

    Fixed building tables.

[33mcommit 0e9ac7cf3b6d67e2ad5f4ddbf182efae177d2949[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 14:38:46 2018 -0400

    testing meld for joe

[33mcommit 3b68b288a608f994bc212cdd589f655c45722a32[m
Merge: 7792a8e 01b1b88
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 14:24:44 2018 -0400

    tested meld

[33mcommit 7792a8e8a5ab88717f893ceb9bca3c6cf90f2713[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 14:23:15 2018 -0400

    testing meld

[33mcommit 01b1b88ac3972987a855075af7b3b30f07e2f34c[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 23 14:23:15 2018 -0400

    Testing meld.

[33mcommit db831f59d40650af3c7225291f97ea33ae8a1452[m
Merge: e6e41e8 80e5d9a
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 13:55:27 2018 -0400

    merged and updated ui

[33mcommit e6e41e853b7dec810a622fc9b4621cd003870382[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 23 13:44:45 2018 -0400

    continued working on db

[33mcommit 80e5d9a72354c63e20b5ae1a1b6b55e6988575e0[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 19:28:14 2018 -0400

    Made room for emergency selector in the GUI when creating a simulation. Will hold off on having that affect value added to database until I determine if it is worth it to have a foreign key here.

[33mcommit 475bad5d0f1da64a68ed9083b2896e61b95e69e2[m
Merge: 45b2dc5 56701f7
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 18:54:28 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 45b2dc5e8318bba1c255f38d12470e4500daf178[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 18:54:21 2018 -0400

    Finished adding in creating emergency functionality to the GUI. It uses the emergency database as well.

[33mcommit 56701f795af653ca0fc2d53ede260f1bf1321753[m
Merge: 43052f0 38a5750
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 18:14:34 2018 -0400

    fix directory

[33mcommit 43052f0ae15cc2dfcb2de64692626cf0ac678aec[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 18:10:32 2018 -0400

    create table function added and it will not removed earlier table. updated add-user function

[33mcommit 38a5750cf4c4e23cab770a02ba9751f3a031c743[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 17:20:51 2018 -0400

    Working on adding emergency creation GUI.

[33mcommit 5a88e34ccdbad764b79cdb44d7f2af24912d4c38[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 16:37:55 2018 -0400

    fixed wrong directory

[33mcommit fe475937230934eeec24f706d4748784c27f1954[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 16:37:15 2018 -0400

    first responder register added

[33mcommit 40c81151ebcbfdeae031b60cc7e689482d2a9559[m
Merge: 1bcca76 8ae86d0
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 16:17:33 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 1bcca76a892956689c22dc25691df5ed22b01a19[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 16:17:27 2018 -0400

    Created emergency databases and emergency item container. Tested the emergency database in the test file.

[33mcommit 8ae86d06b5cccb76ed085fefa68850091193530d[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 16:14:34 2018 -0400

    Updated select user method.

[33mcommit 63d34d5fbe6dfcfce06a7e3470c0f0df688203ce[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 16:02:38 2018 -0400

    Updated select user method. updated registration form with responder

[33mcommit a7b840cb2e10cf68f7f1ffc01e1692651d31c16c[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 15:12:45 2018 -0400

    Fixing missing label

[33mcommit 70bf81d2d9291859f30b023b640d5d22f4d41173[m
Merge: f12a147 b62fd1f
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 15:09:12 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit f12a147317ae431a7fbe8c66b2d72bf80ea05b33[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 15:09:09 2018 -0400

    fixed error in main window

[33mcommit b62fd1faf16810a3c143a02e143b91643a2c06db[m
Merge: 19122bf ae90e21
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 15:00:49 2018 -0400

    merged and added .sql file

[33mcommit 19122bfef8f4693d8046da623c59437ba848798f[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 14:57:59 2018 -0400

    added database build file

[33mcommit 2eeb140493581f8f4d0a34acf73646535fdb9a80[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 14:41:07 2018 -0400

    groups are listed in the group folder now

[33mcommit ae90e21e99db498be1bb5b06c67f80630ce2afcb[m
Merge: 6bef06c 5dbc190
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 14:35:50 2018 -0400

    Merge branch 'master' of 139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin
    merge ui
    g the commit.

[33mcommit 6bef06c1c5a6662b27d346f97a05fd39a3b1e5ff[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 14:35:40 2018 -0400

    fixed merging UI issues

[33mcommit 5dbc190edc050036fbea1676859ed47a52413fe5[m
Merge: f1620fa c49cc08
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 14:31:12 2018 -0400

    fixed merge conflict

[33mcommit f1620fa1e1add24bf163ecddf414f1503a7a6575[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 14:28:24 2018 -0400

    Having view simulation work properly by pulling from database

[33mcommit c49cc08d7f9ab781208000e31fc047c8dfb43858[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 14:16:17 2018 -0400

    fixed merge

[33mcommit 1052dc20c70e59ea6ce65033d7a10ba22241ecd3[m
Merge: 41babe7 a9f471f
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 14:05:35 2018 -0400

    merged - hopefully everything is as it should be

[33mcommit 41babe727ee147e5054bc43056acb4952500f6c5[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sun Apr 22 13:56:50 2018 -0400

    finished populating group table

[33mcommit a9f471fc6122957d49b51bb1fc836fa2b2641409[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 13:06:40 2018 -0400

    break in as planner not civilian

[33mcommit ef31d754d707bd5439de22bf11c7b1971405d490[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 12:55:53 2018 -0400

    Fixed GUI so it matches the changed Simulation Database.

[33mcommit 1c16f5ddf5df53315e57f019562277caeb3d8da7[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sun Apr 22 12:36:14 2018 -0400

    Modified the Simulation database as it must be changed for certain features to work as intended.

[33mcommit 5d63dbe9e3dd6ba670e0681ed32dad604e5cc37f[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 00:26:42 2018 -0400

    clicking cancel button now clears the content of registration form

[33mcommit d2ce5fd640a82c7fbd59479bd8884b542deee09b[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sun Apr 22 00:18:03 2018 -0400

    added seperate menu page for different type of user. Added button interaction to filter user.Simplifid login and register method in mainwindow

[33mcommit 4a5ba45b10fda32f68df21dfdf864c1ea5a0690c[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 23:50:34 2018 -0400

    updated login and register functions. Added checking role method for login and register different types of users. Added alerts for invalid register and invalid login. added break in button for testing purposes.

[33mcommit 3389517882a526684d95f2cc8402fbbd141e6049[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 21:42:30 2018 -0400

    changing database directory

[33mcommit e4ed3cf188454d05399494c81476670bf6b83e12[m
Merge: 4b2c3b4 ff796bc
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 21:40:56 2018 -0400

    merge for login and register

[33mcommit 4b2c3b4026da81711e9ff66db3b3e85ffa3f6c77[m
Merge: 30b80bc bf4e077
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 21:37:47 2018 -0400

    added login function and categorized registering

[33mcommit ff796bc91f7719fcd413f3b93090e06922c485b7[m
Merge: 117777e b577df0
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 18:52:11 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 117777ed3d703e82ffc9a0d1b71bbf0a7092a86b[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 18:52:07 2018 -0400

    fixed insert user group test

[33mcommit b577df02c6682a4fccad48405683982c2d39bd5b[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 18:39:19 2018 -0400

    Finished adding in the essential windows for the simulation GUI components. Now I just need to get the database creation in the ui class working so these windows can display the proper information at a given time.

[33mcommit 62dd2254e041541563be2dbcf00c1a3a4ef939c1[m
Merge: ca9f43e bf4e077
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 18:20:06 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit ca9f43ee5a237a33e0eaec3e4fbdd6cc6424bfed[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 18:19:55 2018 -0400

    Wrote a unit test for the simulation tables in the database. Created more pages for the simulation GUI. Still trying to figure out why database will not have tables created when called from the ui though.

[33mcommit 30b80bccbda1ef52378c2dcec74c91601d902314[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 18:06:22 2018 -0400

    updating registering function. Added roles to user table

[33mcommit bf4e077929522cd999ffe28ed872c94b991ead85[m
Merge: 0c938f2 65b5bf2
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 17:48:51 2018 -0400

    merged maincontroller

[33mcommit 0c938f264d46d77bda4c31b3483f3b175eb42887[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 17:31:50 2018 -0400

    began login functionality

[33mcommit 65b5bf2c792448adf6758cf578c150077de82588[m
Merge: bbd955c 988f2f5
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 16:59:53 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit bbd955c0e5334011aac82988c00045bbe0190d2a[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 16:59:50 2018 -0400

    Fixed tabbing issue on simulation GUI.

[33mcommit 988f2f56dfdfee69c4305d753739f140c6875331[m
Merge: 18b6f7c c0a51a9
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 16:45:32 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 18b6f7c444e0693d3bd915988e2972fdb4e5289e[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 16:45:29 2018 -0400

    userGroups are now working

[33mcommit c0a51a987b8f6d2f4d8a6ec943402d8b6ca64835[m
Merge: 2d8a5d8 0808c2d
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 16:43:14 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 2d8a5d80e580f965470a558856b6ac78c942a3ac[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 16:43:11 2018 -0400

    Making minor changes.

[33mcommit 0808c2deeccac1b2eb4fae65e9d5d2e2ab2fe611[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 16:33:40 2018 -0400

    fixed unit test. Deleted delete group in group

[33mcommit a4db8bddf3649bba1eeb0e2b23e186910eda9ef3[m
Merge: b1af49a b22fdcc
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 16:12:13 2018 -0400

    Merge

[33mcommit b1af49a25cf600b0bb6b14679c0b95371bd86468[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 16:01:14 2018 -0400

    modified controller constructor

[33mcommit b22fdcc244edfcf9996848318264cad73e8736b5[m
Merge: 3208432 1bbff59
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 15:57:19 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 3208432c97552793bc345d8249d815835623cd9d[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 15:57:12 2018 -0400

    made userGroups table

[33mcommit 1bbff5925b4fab6368ad9e82b112b6d41b7314c6[m
Merge: 7d663ee 74d7624
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 15:53:50 2018 -0400

    Fixed merge conflict.

[33mcommit 7d663eea2458cfc63ae410465da95dc1f620fbab[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 15:51:19 2018 -0400

    Had simulations be added to the db. A few bugs persist.

[33mcommit 74d762490a3d83b1fa9ecab20f8fbbe6ed78d518[m
Merge: 7fa6e87 93f7da5
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 15:09:08 2018 -0400

    merged with the fixed version

[33mcommit 7fa6e87f0b431f03b4a89cef84f44ac301634a8b[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 15:04:58 2018 -0400

    worked in maincontroller

[33mcommit 93f7da57d185fe44e7b4abd89bf6a41e09ebab2b[m
Merge: 069269c a62d781
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 15:03:14 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 069269ce224accdf87a115c887bf363e78d1376d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 15:03:08 2018 -0400

    Fixed bug in the gui.pro file.

[33mcommit a62d781db7ee61f10172d8a491ac1f737dfb7a2e[m
Merge: 7ae493e efa3ce4
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 14:57:42 2018 -0400

    Fixing registering function

[33mcommit 7ae493e7395ec09ad9d21dc7b3c0590147a42eaf[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 14:53:57 2018 -0400

    Fixing registering function

[33mcommit fa9ddefacf89eaafcd982c8ce0337729df725c68[m
Merge: 27a622e efa3ce4
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 14:31:18 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 27a622e2d2e83081b7edcb754bc169d4e4250678[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 14:31:13 2018 -0400

    added userGroup table

[33mcommit efa3ce47846cd2997e5a8c9600d275a80cfa69e1[m
Merge: 5ec83c1 269a399
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 14:25:18 2018 -0400

    fixed merge conflict

[33mcommit 5ec83c1e1228f04723afdc8a148c23e440259be1[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 14:14:29 2018 -0400

    Continued to add to Simulation GUI. It can now accept in the text and currently in progress of adding that information to the database.

[33mcommit 269a3990669656c95c6fb41ce0007cb1da543725[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 14:14:21 2018 -0400

    fix bug in controller

[33mcommit 31f2218c183b913b4e7b062e0a85bbf69eb1992c[m
Merge: 6e238b5 759f62e
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 14:11:09 2018 -0400

    Merge

[33mcommit 6e238b5f06c90a742d4a92042bd7000e520e70e2[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Sat Apr 21 14:01:08 2018 -0400

    Pull and Fix database directory issues

[33mcommit 759f62e9501e39a6fc059661454a9bcddec82809[m
Merge: 9159e2c b56c659
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 12:52:11 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 9159e2c39d958fbf8eecb5ef204f5941f13cb444[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 12:52:03 2018 -0400

    Adding more to the GUI for the simulation functionality

[33mcommit b56c659e2df59bc19043f0677b04901cb2d5545d[m
Merge: d90feab 4bfd50b
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 12:47:32 2018 -0400

    fixed issue with pro file

[33mcommit d90feab3e44035c91ca96714b01168eda349bf4d[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Sat Apr 21 12:39:07 2018 -0400

    added more db tests for groups

[33mcommit e809a222afa802505c337063ac2263d8ee1d4e6d[m
Merge: 6a87238 4bfd50b
Author: teddickj <teddickj@lafayette.edu>
Date:   Sat Apr 21 12:29:25 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 4bfd50b2da2a476584ea6a887cd20a3017955ae4[m
Merge: 54db000 80a2ef2
Author: Chen Xin <xinc@lafayette.edu>
Date:   Fri Apr 20 22:27:03 2018 -0400

    Merge: added register function and added function to access database from ui

[33mcommit 54db0007150b38b033bc3c4294260e7aa5e4bb34[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Fri Apr 20 22:23:24 2018 -0400

    added register function and added function to access database from ui

[33mcommit 6a87238ef3a54ca765e16c5e2390434c4fd94a07[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Fri Apr 20 13:06:54 2018 -0400

    Changed name of a variable

[33mcommit 80a2ef2d840dd9f1a5a75e34013f18db836c4d12[m
Merge: 97e6829 f3fb189
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Fri Apr 20 12:51:46 2018 -0400

    merged

[33mcommit 97e68297d81da9ca44bba96f75fcbdee653539a4[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Fri Apr 20 12:50:35 2018 -0400

    need to pull

[33mcommit f3fb189b121dffc11ff8c00d5f577c0c67cdee1e[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Thu Apr 19 22:58:56 2018 -0400

    Created a simulation database and fixed the simulation class so it is a child class of a database object. Also added more GUI to actual create the simulations.

[33mcommit 485ba47eee7e76815cea859be939b2f17eb68ff7[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Thu Apr 19 21:21:54 2018 -0400

    Changed simulation controller to a value of database. Controller will be slightly different when implemented. Added proper GUI components for adding in a new Simulation.

[33mcommit ef7672e8a5d6d884276d991dd2328e2826c2c78d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Thu Apr 19 18:02:02 2018 -0400

    Created a class to control the simulation, which is essential for testing the software.

[33mcommit b6ee332abcccbcb73d6850728cf0248a30e95224[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Thu Apr 19 17:09:08 2018 -0400

    Fixed complier issues. Included necessary files in gui.pro

[33mcommit 6767f9fb739e365b4be7dfd58dd3b43542100046[m
Author: Chen Xin <xinc@lafayette.edu>
Date:   Thu Apr 19 16:48:47 2018 -0400

    Fixed a bug on unittestthat Mac compiler will not pause the program when a pointer is deleted twice. Updated db_user methods and dB_user update_cmd and now all unittests pass through mac's compiler

[33mcommit 70037b7236eeb61536d4e84f3cbd16284420ea81[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 19 12:17:21 2018 -0400

    fixed merge...even more

[33mcommit 827fed4d29ce78413526bfd975af5f5df9b52fda[m
Merge: 208f27c 3a18b02
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 19 12:14:35 2018 -0400

    merged controller file

[33mcommit 208f27cb3adf2ee52c00d9ccbffde514b8d44fb7[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Thu Apr 19 12:13:07 2018 -0400

    fixed the controller

[33mcommit 3a18b025449d259385e369773772235841e5de4c[m
Author: Chen Xin <chenxin@MacBook-Pro-3.local>
Date:   Thu Apr 19 00:22:46 2018 -0400

    Fixed unexpected quitting error when window is closed

[33mcommit 39f359d58209eb06f36253efe3e804d0f6ad454a[m
Merge: 4b9f63d 4bc4737
Author: Chen Xin <chenxin@MacBook-Pro-3.local>
Date:   Thu Apr 19 00:10:57 2018 -0400

    Merged controllers and db_manager

[33mcommit 4b9f63d17694712aa2a15229ba44e8c4c1ace6e4[m
Author: Chen Xin <chenxin@MacBook-Pro-3.local>
Date:   Wed Apr 18 23:58:36 2018 -0400

    Main controller function for registering users

[33mcommit fea21c40f562736f0cfb23beed3adeae599cf4c8[m
Author: Chen Xin <chenxin@MacBook-Pro-3.local>
Date:   Wed Apr 18 23:55:56 2018 -0400

    Main controller function for registering users

[33mcommit 4bc473714f0367ba529e60cfdc4772544ff29732[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 21:22:22 2018 -0400

    added new tests and group class

[33mcommit eadadbe94e7278406aa7338797470da4a40c0e6e[m
Merge: 7c8e71b b7f45b9
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 18 17:14:21 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 7c8e71bbb2ee67a61bd81850a543a906381d7fc2[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 18 17:14:17 2018 -0400

    Modified the GUI, and made the Trigger area read only.

[33mcommit b7f45b922110260e53b1801189fa96d86f163d0c[m
Merge: b986e01 638a5fb
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 16:52:04 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit b986e0174e7885b3898cf4435c10586f233de817[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 16:51:50 2018 -0400

    Updated tests for database

[33mcommit 638a5fb1f873b5765bf3acb699c4376ed2bb83a9[m
Merge: 184c5d4 9c4a5d7
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 18 15:25:34 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 184c5d4ed82651c11d329b8bad41ee8ba3ca4515[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 18 15:25:28 2018 -0400

    Removed permission window for location. Now it just assumes the user will give their location.

[33mcommit 9c4a5d712468ff6f52a90e06ab0b84932528a0e3[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 15:23:30 2018 -0400

    updated database functions

[33mcommit 4193184cb8c4dabc6a2e67340828c5d828909a44[m
Merge: d0a77b2 f2e2945
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 15:13:07 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit d0a77b2c3a5583a64d7e3d315918b594a5fbb7a5[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 15:13:03 2018 -0400

    preparing for pull

[33mcommit f2e2945371954dc111df2877375e150d57a449c9[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 18 15:12:52 2018 -0400

    taking out high accuracy because it did not work as intended.

[33mcommit 5e9fd550bc03546ae5b62f53c28ddc3bec524845[m
Merge: 93f429f e6c6e2e
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 12:40:49 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 93f429f127cea99063712ea29fa04b553b61d78f[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 18 12:40:44 2018 -0400

    worked on controller

[33mcommit e6c6e2e499ef71650fb2fa0f802679e3c91f5d8e[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 17 16:46:02 2018 -0400

    Added in custom markers, fixed 'asking permission for location' window, and refactored javascript map code.

[33mcommit 5bd98de1f3a1aa6c5f533b8de5e6166897ea9100[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 17 14:16:51 2018 -0400

    adding label functionality to map

[33mcommit e04e4c025023e939cbd0c4feeeac96746a632537[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Mon Apr 16 15:44:06 2018 -0400

    restructured project to be a subdirs project

[33mcommit 69a076268afacb8e2b17ee368294a0ea061faa56[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Fri Apr 13 23:29:38 2018 -0400

    Finally got the Geolocation to work after modifying the javascript, and cpp and h window files

[33mcommit 6f1495ddbe34196044b0f2ce5b36d10ab11fe44d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Fri Apr 13 15:47:03 2018 -0400

    Still working on getting location working

[33mcommit 3df9b35ed7a0a9f683adade633464d8d1c9d27d7[m
Author: xinc <xinc@lafayette.edu>
Date:   Thu Apr 12 23:12:12 2018 -0400

    Added comments for button navigation. Added class responder and planner. Made changes on UI

[33mcommit 239c761f2d68f9c8a84e105f55d68c1d11dd7856[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Thu Apr 12 11:59:05 2018 -0400

    Working on javascript file.

[33mcommit 8f5d0264a55ef422de491800fad225f36c97eb0f[m
Merge: 32172a8 3d8b0f8
Author: teddickj <teddickj@lafayette.edu>
Date:   Thu Apr 12 11:01:22 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 3d8b0f866a83aa5c92cc0e0100c6a1df6b669ecd[m
Merge: 4ac61b0 b0d1588
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 18:26:09 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 4ac61b03a1919d08adbe911c80a495b8ab39f622[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 18:26:02 2018 -0400

    Created skeletal user, db item, and civilian classes and implemented them polymorphically in the db

[33mcommit 32172a89660c6dff5b3cffe4f6858716592bc4a0[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 11 15:47:50 2018 -0400

    working with javascript

[33mcommit b0d1588ccf9194f0967991e1ee17cad30290e15b[m
Author: xinc <xinc@lafayette.edu>
Date:   Wed Apr 11 15:38:32 2018 -0400

    UI updates, removing password

[33mcommit 872ec78278c5c022779cfd677f4e2c436b6d7840[m
Merge: 15232be 43487f7
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 15:26:43 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin

[33mcommit 15232be9e2ab61c248247aafb93c8ff2dd866fc6[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 15:26:39 2018 -0400

    Started user classes (do not compile) and updated db

[33mcommit 43487f7b88bf6bf21e76c893fb655604f1681f90[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 11 15:13:13 2018 -0400

    Working with map javascript.

[33mcommit dd03764bc633adee60894a3a066b6649cbc3daeb[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Apr 11 14:27:12 2018 -0400

    Fixed main menu GUI

[33mcommit bf740ffe68c733006a4883358e19dc73c23b4dd4[m
Merge: 3b23b23 ceb5919
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 13:29:14 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin
    
    Finished database

[33mcommit 3b23b2362d2517e818b9a37fad2780862a15b090[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Wed Apr 11 13:29:06 2018 -0400

    Database is now functional

[33mcommit ceb591972ab52c68324bd46bd491db02195be50e[m
Author: xinc <xinc@lafayette.edu>
Date:   Wed Apr 11 07:16:05 2018 -0400

    Added initial parts of UI navigation for testing

[33mcommit a90a5f4298945c5a85d934afab4dde08e682ebc6[m
Merge: 743f0a1 8998372
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 10 22:10:00 2018 -0400

    Merge branch 'master' of ssh://139.147.9.185:/home/spr2018_s1g2/repo_project_teddick_fuller_xin
    
    Added a new folder containing the database classes.

[33mcommit 743f0a124ca451cc3687208a0299930044c48bec[m
Author: Ben Fuller <fullerb@lafayette.edu>
Date:   Tue Apr 10 22:09:54 2018 -0400

    Added prototype db classes

[33mcommit 899837218c8ee4060c13d19b7588573bd0243a49[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 10 17:26:21 2018 -0400

    Added in map functionality to program

[33mcommit 59705771baa8ef6ec5296500cb52793afa5a5d6d[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Tue Apr 10 16:31:59 2018 -0400

    trying to get map functionality working

[33mcommit 69d2baadd947a6650721a051e4a072cdeb87ac24[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 9 15:15:39 2018 -0400

    Testing GUI.

[33mcommit 57370058b9db050b90326b1cfd58215a7dac4d33[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 9 15:10:58 2018 -0400

    cleaning up repo.

[33mcommit 98063b2c79205c4b3631401295a355abb0b42403[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 9 15:05:46 2018 -0400

    creating project first qt project file.

[33mcommit 142e1508a248b4629c21b7f8e6afabe02570c2df[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 9 14:32:38 2018 -0400

    added .gitignore file to repo.

[33mcommit 50a387cba51c2a34756d80bf27e6b4fc7a0919d4[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Mon Apr 9 14:27:28 2018 -0400

    removing test file from repo to clean it up for the addition of project files.

[33mcommit 4cd973943fc5e44a96b12b537958e22306b7575f[m
Author: teddickj <teddickj@lafayette.edu>
Date:   Wed Mar 28 14:57:00 2018 -0400

    testing that repo works
