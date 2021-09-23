#include "proto/generated/cpp/telemetry.pb.h"
#include "proto/generated/cpp/telemetry.grpc.pb.h"
#include "src/include/pos_event_id.h"
#include "src/logger/logger.h"
#include "src/telemetry/telemetry_client/grpc_global_publisher.h"
#include "src/telemetry/telemetry_client/telemetry_client.h"
#include "src/telemetry/telemetry_manager/telemetry_manager_service.h"

#include <gtest/gtest.h>
namespace pos
{
TEST(GrpcGlobalPublisher, GrpcGlobalPublisher_)
{
    // Given: a grpc server
    string server_address("0.0.0.0:50051");
    TelemetryManagerService* tmServer = new TelemetryManagerService();
    usleep(1000);

    // Given: a grpc client
    GrpcGlobalPublisher* grpcClient = new GrpcGlobalPublisher(tmServer, nullptr);
    MetricUint32 metric;
    metric.SetMetric(TEL_ALLOCATOR_FREE_SEGMENT_COUNT, std::time(nullptr), 10, "time");

    // When 1: publish()
    int ret = grpcClient->PublishToServer(metric);

    // Then 1
    EXPECT_EQ(0, ret);
    delete grpcClient;
    delete tmServer;
}

TEST(GrpcGlobalPublisher, PublishToServer_)
{
    // Given: a grpc server
    string server_address("0.0.0.0:50051");
    TelemetryManagerService* tmServer = new TelemetryManagerService();
    usleep(1000);

    // Given: a grpc client
    GrpcGlobalPublisher* grpcClient = new GrpcGlobalPublisher(tmServer, nullptr);
    MetricString metric;
    metric.SetMetric("newAir", std::time(nullptr), "myDataDataData", "time");

    // When 1: publish()
    int ret = grpcClient->PublishToServer(metric);

    // Then 1
    EXPECT_EQ(0, ret);
    delete grpcClient;
    delete tmServer;
}

} // namespace pos
