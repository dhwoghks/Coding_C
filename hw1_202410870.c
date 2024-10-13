#include <stdio.h>

int main() {
    int rt_avg, service_avg, other_avg;
    double sh_discount = 0, kb_discount = 0;
    double sh_rate_rt = 0, sh_rate_sv = 0, kb_rate_rt = 0, kb_rate_sv = 0;
    int prev_total_sh = 0, prev_total_kb = 0;

    printf("*** ����/���� K-�н� üũī�� �ùķ��̼� ���α׷� ***\n");

    while (1) {
        printf("����� ���߱��� ���: ");
        scanf_s("%d", &rt_avg);
        if (rt_avg < 0) {
            printf("0�� �̻��� ������ �ٽ� �Է��ϼ���.\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        printf("����� ��Ȱ ���� ������: ");
        scanf_s("%d", &service_avg);
        if (service_avg < 0) {
            printf("0�� �̻��� ������ �ٽ� �Է��ϼ���.\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        printf("����� ��Ÿ ������: ");
        scanf_s("%d", &other_avg);
        if (other_avg < 0) {
            printf("0�� �̻��� ������ �ٽ� �Է��ϼ���.\n");
            continue;
        }
        else {
            break;
        }
    }

    prev_total_sh = rt_avg + service_avg + other_avg;

    if (prev_total_sh >= 500000) {
        sh_rate_rt = 0.1;
        sh_rate_sv = 0.02;
        if (rt_avg * sh_rate_rt > 5000) {
            sh_discount += 5000;
        }
        else {
            sh_discount += rt_avg * sh_rate_rt;
        }
        if (service_avg * sh_rate_sv > 5000) {
            sh_discount += 5000;
        }
        else {
            sh_discount += service_avg * sh_rate_sv;
        }
    }
    else if (prev_total_sh >= 200000) {
        sh_rate_rt = 0.1;
        sh_rate_sv = 0.02;
        if (rt_avg * sh_rate_rt > 2000) {
            sh_discount += 2000;
        }
        else {
            sh_discount += rt_avg * sh_rate_rt;
        }
        if (service_avg * sh_rate_sv > 2000) {
            sh_discount += 2000;
        }
        else {
            sh_discount += service_avg * sh_rate_sv;
        }
    }

    prev_total_kb = rt_avg + service_avg + other_avg;

    if (prev_total_kb >= 200000) {
        kb_rate_rt = 0.1;
        kb_rate_sv = 0.02;
        if (rt_avg * kb_rate_rt > 2000) {
            kb_discount += 2000;
        }
        else {
            kb_discount += rt_avg * kb_rate_rt;
        }
        if (service_avg * kb_rate_sv > 8000) {
            kb_discount += 8000;
        }
        else {
            kb_discount += service_avg * kb_rate_sv;
        }
    }

    printf("���� K-�н� üũī���� ���� ���� �ݾ��� %.0f���̸�, ���η��� %.2f%%�Դϴ�.\n", sh_discount, (sh_discount / prev_total_sh) * 100);
    printf("���� K-�н� üũī���� ���� ���� �ݾ��� %.0f���̸�, ���η��� %.2f%%�Դϴ�.\n", kb_discount, (kb_discount / prev_total_kb) * 100);

    if (sh_discount > kb_discount) {
        printf("���� ���� K-�н� üũī�尡 �� ���� �����Դϴ�.\n");
    }
    else if (kb_discount > sh_discount) {
        printf("���� ���� K-�н� üũī�尡 �� ���� �����Դϴ�.\n");
    }
    else {
        printf("���� ��� ���� �����ϼŵ� ������ �����մϴ�.\n");
    }

    return 0;
}
