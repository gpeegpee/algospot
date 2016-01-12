FROM ubuntu:14.04
MAINTAINER GangHeok Kim "gpeegpee@gmail.com"

RUN apt-get update && \
    apt-get --no-install-recommends install -q -y openjdk-7-jre-headless && \
    rm -rf /var/lib/apt/lists/*

RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 9B7D32F2D50582E6
RUN	echo "deb http://pkg.jenkins-ci.org/debian binary/" > /etc/apt/sources.list.d/jenkins.list && \
	apt-get update && apt-get install -q -y jenkins
ENV JENKINS_HOME /jenkins
RUN service jenkins start
#ENTRYPOINT ["java", "-jar", "/opt/jenkins.war"]
EXPOSE 8080
#CMD [""]
