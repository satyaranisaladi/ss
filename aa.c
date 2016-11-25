I. Installing JAVA JDK
Login as root
sudo –s
Install Jave Runtime
sudo apt-get install default-jre
Install Java JDK (OpenJDK v 1.7 or newer)
sudo apt-get update
sudo apt-get install default-jdk
                Checking Java verison
Java --version

II. Install Secure Shell
Install (SSH and RSYNC)
sudo apt-get install ssh
sudo apt-get install rsync
Create and Setup SSH Certificates (Setup passphraseless ssh)
To enable password-less login, generate a new SSH key with an empty passphrase:
Use Hadoop User:
ssh-keygen -t dsa -P '' -f ~/.ssh/id_dsa
cat ~/.ssh/id_dsa.pub >> ~/.ssh/authorized_keys

III. Fetch and Install Hadoop
Fetcth Hadoop (Stable Version)
wget http://apache.tradebit.com/pub/hadoop/common/current/hadoop-2.6.0.tar.gz
Extract File
tar xfz hadoop-2.6.0.tar.gz
Move to local (Runing Directory)
mv hadoop-2.6.0 /usr/local/hadoop

IV. Edit Hadoop Configuration Files
Get Java Correct Path
update-alternatives --config java
                /usr/lib/jvm/java-7-openjdk-i386 /jre/bin/java
Modifing The following Files
~/.bashrc
/usr/local/hadoop/etc/hadoop/hadoop-env.sh
/usr/local/hadoop/etc/hadoop/core-site.xml
/usr/local/hadoop/etc/hadoop/yarn-site.xml
/usr/local/hadoop/etc/hadoop/mapred-site.xml
/usr/local/hadoop/etc/hadoop/hdfs-site.xml
(1)~/.bashrc
nano ~/.bashrc
Add the following to the end file after modify the java_home and Hadoop_install, Change JAVA_HOME to Correct path you getting above, and HADOOP_INSTALL to your hadoop folder room
#HADOOP VARIABLES START
export JAVA_HOME=/usr/lib/jvm/java-7-openjdk-i386
export HADOOP_INSTALL=/usr/local/hadoop
export PATH=$PATH:$HADOOP_INSTALL/bin
export PATH=$PATH:$HADOOP_INSTALL/sbin
export HADOOP_MAPRED_HOME=$HADOOP_INSTALL
export HADOOP_COMMON_HOME=$HADOOP_INSTALL
export HADOOP_HDFS_HOME=$HADOOP_INSTALL
export YARN_HOME=$HADOOP_INSTALL
export HADOOP_COMMON_LIB_NATIVE_DIR=$HADOOP_INSTALL/lib/native
export HADOOP_OPTS="-Djava.library.path=$HADOOP_INSTALL/lib"
#HADOOP VARIABLES END
Save file and close then Refresh Source using the following command
source ~/.bashrc

(2) /usr/local/hadoop/etc/hadoop/hadoop-env.sh
nano /usr/local/hadoop/etc/hadoop/hadoop-env.sh
                Update the JAVA_HOME
JAVA_HOME=/usr/lib/jvm/java-7-openjdk-i386
                Save and close the file
(3)/usr/local/hadoop/etc/hadoop/core-site.xml
nano /usr/local/hadoop/etc/hadoop/core-site.xml
Add the following to the configuration Tag
<property>
   <name>fs.default.name</name>
   <value>hdfs://localhost:9000</value>
</property>
                Save and close the file
(4)/usr/local/hadoop/etc/hadoop/yarn-site.xml
nano /usr/local/hadoop/etc/hadoop/yarn-site.xml
Add the following to the configuration Tag
<property>
   <name>yarn.nodemanager.aux-services</name>
   <value>mapreduce_shuffle</value>
</property>
<property>
   <name>yarn.nodemanager.aux-services.mapreduce.shuffle.class</name>
   <value>org.apache.hadoop.mapred.ShuffleHandler</value>
</property>
                Save and close the file
(5)/usr/local/hadoop/etc/hadoop/mapred-site.xml
                Copy template
cp /usr/local/hadoop/etc/hadoop/mapred-site.xml.template  /usr/local/hadoop/etc/hadoop/mapred-site.xml
                Modify file
nano /usr/local/hadoop/etc/hadoop/mapred-site.xml
Add the following to the configuration Tag
<property>
   <name>mapreduce.framework.name</name>
   <value>yarn</value>
</property>
                Save and close the file
(6)/usr/local/hadoop/etc/hadoop/hdfs-site.xml
                Create two directory for hadoop storage
mkdir -p /usr/local/hadoop_store/hdfs/namenode
mkdir -p /usr/local/hadoop_store/hdfs/datanode
                Modify the file
nano /usr/local/hadoop/etc/hadoop/hdfs-site.xml
Add the following to the configuration Tag
<property>
   <name>dfs.replication</name>
   <value>1</value>
 </property>
 <property>
   <name>dfs.namenode.name.dir</name>
   <value>file:/usr/local/hadoop_store/hdfs/namenode</value>
 </property>
 <property>
   <name>dfs.datanode.data.dir</name>
   <value>file:/usr/local/hadoop_store/hdfs/datanode</value>
 </property>
                Save and close the file

V. Change folder permission
                Replace qursaan: with your hadoop users to be the owner of the folder

sudo chown qursaan:qursaan -R /usr/local/hadoop
sudo chown qursaan:qursaan -R /usr/local/hadoop_store

                also give the folder the full permission

sudo chmod -R 777 /usr/local/hadoop
sudo chmod -R 777 /usr/local/hadoop_store

VI. Format the New Hadoop Filesystem
Using Hadoop user (not superuser)
hdfs namenode –format

VII. Start hadoop
                Using Hadoop user (not superuser)
start-dfs.sh
start-yarn.sh
OR to run all
start-all.sh

