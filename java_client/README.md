# Java protobuf events client

This is a client which expose a post endpoint on a configurable http port for sending events in the following format:  
```
{  
"timestamp" : 1518609008,  
"userId" : 1123,  
"event" : "2 hours of downtime occured due to the release of version 1.0.5 of the
system"  
}
```

## Technology stack

* SpringBoot 2.0.3.RELEASE
* gradle 4.5.1
* swagger 2.6.1 for endpoint documentation and testing
* com.google.protobuf 3.5.1

## Usage

* To compile the project, from root folder of the project run: ```gradlew clean build```  
* Run project with: ``` gradlew bootRun ``` or ```java -jar build/libs/java_client-0.0.1-SNAPSHOT.jar```
* Test the endpoint by accessing: ```http://localhost:9080/swagger-ui.html```

*The application uses the tcp socket for sending the events to the cpp server. The socket host and port are configured inside resources/application.yaml*